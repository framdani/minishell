/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_final.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 10:12:35 by akhalidy          #+#    #+#             */
/*   Updated: 2021/06/29 19:14:56 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_get_cmd_path(char *cmd, char *pathenv)
{
	struct stat	buf;
	char		*path;
	char		*pfree;
	char		**split;
	int			i;

	i = 0;
	split = ft_split(pathenv, ':');
	while (split[i])
	{
		path = ft_strjoin("/", cmd);
		pfree = path;
		path = ft_strjoin(split[i], path);
		free(pfree);
		if (!stat(path, &buf))
		{
			ft_free(split);
			return (path);
		}
		free(path);
		i++;
	}
	ft_free(split);
	return (NULL);
}

int	ft_path_is_dir(char *args, char **path)
{
	DIR	*dir;
	
	if (!args)
		return (-1);
	dir =  opendir(args);
	if (!dir)
	{
		*path = ft_strdup(args);
		return (1);
	}
	closedir(dir);
	return (0);
}

int	ft_check_path(char **path, char **args, t_list *envl)
{
	t_list	*pathenv;

	*path = NULL;
	if (**args == '\0')
		*path = NULL;
	else if(**args == '/' || !ft_strncmp(*args, "./", 2) || !ft_strncmp(*args, "../", 3))
	{
		if (!ft_path_is_dir(*args, path))
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(args[0] , 2);
			ft_putendl_fd(": is a directory", 2);
			return (126);
		}
	}
	else
	{
		pathenv = ft_find_node(envl, "PATH");
		if (pathenv)
			*path = ft_get_cmd_path(args[0], pathenv->value);
		else
			*path = ft_get_cmd_path(args[0], ".");
	}
	if (!*path)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(args[0] , 2);
		ft_putendl_fd(": command not found", 2);
		return (127);
	}
	return (0);
}

int	ft_exec_cmd(t_list *envl, char **args, int fork_on)
{
	char	*path;
	char	**envp;
	int		status;
	int		ret;
	int		id;
	
	ret = ft_check_path(&path, args, envl);
	if (!ret)
	{
		envp = ft_list_to_arr(envl);
		if (fork_on)
			id = fork();
		if ((!id && fork_on) || !fork_on)
		{
			execve(path, args, envp);
			ft_putendl_fd(strerror(errno), 2);
			ft_exit_child();
		}
		if (fork_on && id)
		{
			waitpid(id, &status, 0);
			ret = WEXITSTATUS(status);
		}
		ft_free(envp);
	}
	free(path);
	return (ret);
}
