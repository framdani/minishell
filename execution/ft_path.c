/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:57:28 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/12 15:00:36 by akhalidy         ###   ########.fr       */
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
