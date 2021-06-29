/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_final.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 10:12:35 by akhalidy          #+#    #+#             */
/*   Updated: 2021/06/27 17:21:23 by akhalidy         ###   ########.fr       */
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
	
	//check if I have a binary file
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
	// else if I have a simple cmd which i should find it s binary file  
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
	if (path)
		free(path);
	return (ret);
}

/*void	ft_launch_execution(t_cmd *cmds, t_list	*envl)
{
	int		ret;

	if (!cmds->next)
		ret = ft_red_smpl_cmd(cmds, envl);
	else
		ret = ft_pipe(cmds, envl);
	unlink("/tmp/file");
	printf("ret = %d\n", ret);
}

int	ft_launch_exec(char **args, t_list *envl, int fork)
{
	int	ret;

	ret = 0;
	if (!ft_strncmp("echo", *args, 5))
	{
		ft_echo(args + 1, 1);
		if (!fork)
			exit(0);
	}
	else if (!ft_strncmp("env", *args, 4))
	{
		ft_env(envl, 1);
		if (!fork)
			exit(0);
	}
	else if (!ft_strncmp("export", *args, 7))
	{
		ft_export(&envl, args + 1, 1);
		if (!fork)
			exit(0);
	}
	else if (!ft_strncmp("unset", *args, 6))
	{
		ft_unset(&envl, args + 1);
		if (!fork)
			exit(0);
	}
	else if (!ft_strncmp("cd", *args, 3))
	{
		ft_cd(envl, args + 1);
		if (!fork)
			exit(0);
	}
	else if (!ft_strncmp("pwd", *args, 4))
	{
		ft_pwd(envl);
		if (!fork)
			exit(0);
	}
	else if (!ft_strncmp("exit", *args, 5))
		ft_exit(args + 1);
	else
		ret = ft_exec_cmd(envl, args, fork);
	return (ret);
}*/

