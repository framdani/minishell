/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <framdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 10:12:35 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/11 16:04:20 by framdani         ###   ########.fr       */
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

	i = -1;
	if (!pathenv)
		return (NULL);
	split = ft_split(pathenv, ':');
	while (split[++i])
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
	}
	ft_free(split);
	return (NULL);
}

int	ft_path_is_dir(char *args, char **path)
{
	DIR	*dir;

	if (!args)
		return (-1);
	dir = opendir(args);
	if (!dir)
	{
		*path = ft_strdup(args);
		return (1);
	}
	closedir(dir);
	return (0);
}

int	ft_print_exec_error(char *args, char *error, int n_exit)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(args, 2);
	ft_putendl_fd(error, 2);
	return (n_exit);
	//exit(n_exit);
}

int	ft_check_path(char **path, char **args, t_list *envl)
{
	t_list	*pathenv;

	*path = NULL;
	if (!*args)
		exit (0);
	if (**args == '\0')
		*path = NULL;
	else if (**args == '/' || !ft_strncmp(*args, "./", 2)
		|| !ft_strncmp(*args, "../", 3))
	{
		if (!ft_path_is_dir(*args, path))
			return (ft_print_exec_error(args[0], ": is a directory", 126));
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
		return (ft_print_exec_error(args[0], ": command not found", 127));
	return (0);
}

int	ft_exec_cmd(t_list *envl, char **args, int fork_on)
{
	char		*path;
	char		**envp;
	t_exec_hlp	var;

	var.ret = ft_check_path(&path, args, envl);
	if (!var.ret)
	{
		envp = ft_list_to_arr(envl);
		if (fork_on)
			var.id = fork();
		if ((!var.id && fork_on) || !fork_on)
		{
			execve(path, args, envp);
			ft_exit_child();
		}
		if (fork_on && var.id)
			ft_exec_wait(&var);
		ft_free(envp);
	}
	free(path);
	return (var.ret);
}
