/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_outils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:13:25 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/12 14:54:41 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_initialize(int io[3], t_cmd	**new, t_cmd *lst, int *k)
{
	io[0] = 0;
	*new = lst;
	io[2] = -18;
	k = 0;
}

void	ft_pipe_help(int fd[2], int io[3], int *k)
{
	close(fd[1]);
	if (!*k)
		*k = 1;
	io[0] = io[2];
}

void	ft_set_io(int *fd_io, int *io, int out)
{
	if (fd_io[0] != -18)
		io[0] = fd_io[0];
	if (fd_io[1] != -18)
		io[1] = fd_io[1];
	else
		io[1] = out;
}

void	ft_exec_wait(t_exec_hlp *var)
{
	waitpid(var->id, &var->status, 0);
	if (WIFEXITED(var->status))
		var->ret = WEXITSTATUS(var->status);
	else if (WIFSIGNALED(var->status))
	{
		if (WTERMSIG(var->status) == SIGQUIT)
			var->ret = 131;
		else if (WTERMSIG(var->status) == SIGINT)
			var->ret = 130;
	}
	g_help.in_child = 0;
}

int	ft_pipe_last_cmd(t_pipe var, t_cmd *lst, t_list **envl)
{
	int	ret;

	ret = ft_redirect(lst->file, var.fd_io, 0, envl);
	if (g_help.in_here_doc == 254)
	{
		g_help.in_here_doc = 0;
		return (1);
	}
	if (!lst->args[0] && ret != 0)
		return (0);
	ft_set_io(var.fd_io, var.io, 1);
	ft_fork_pipe(var.io, lst->args, envl, &lst->pid);
	if (var.k)
		close(var.fd[0]);
	return (ft_wait_loop(var.new));
}
