/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 10:12:35 by akhalidy          #+#    #+#             */
/*   Updated: 2021/12/20 10:19:46 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_check_sub_shell(char **args)
{
	int	size;

	size = ft_strlen(*args);
	if (size >= 10)
	{
		size -= 10;
		if (!ft_strncmp(*args + size, "/minishell", 11))
			g_help.in_child = -1;
	}
	else
		g_help.in_child = 1;
}

int	ft_exec_cmd(t_list *envl, char **args, int fork_on)
{
	char		*path;
	char		**envp;
	t_exec_hlp	var;

	var.ret = ft_check_path(&path, args, envl);
	if ((var.ret == 127 || var.ret == 126) && !fork_on)
		exit(var.ret);
	if (!var.ret)
	{
		envp = ft_list_to_arr(envl);
		if (fork_on)
			var.id = fork();
		ft_check_sub_shell(args);
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
