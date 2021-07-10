/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:32:49 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/09 15:36:12 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_exit_child(void)
{
	ft_putendl_fd(strerror(errno), 2);
	if (errno == 13 || errno == 21)
		exit(126);
	if (errno == 2 || errno == 22)
		exit(127);
}

void	ft_fork_pipe(int *io, char **args, t_list **envl, int *pid)
{
	if (io[0] == -1)
	{
		*pid = -1;
		return ;
	}
	*pid = fork();
	if (!*pid)
	{
		dup2(io[1], 1);
		dup2(io[0], 0);
		if (io[0] != 0)
			close(io[0]);
		if (io[1] != 1)
			close(io[1]);
		if (io[2] != -18)
			close(io[2]);
		ft_launch_exec(args, envl, 0);
		ft_exit_child();
	}
	if (io[0] != 0)
		close(io[0]);
	if (io[1] != 1)
		close(io[1]);
}

int	ft_wait_loop(t_cmd	*cmds)
{
	int	status;
	int	pid;

	g_help.in_child = 1;
	while (cmds)
	{
		pid = cmds->pid;
		if (cmds->pid > 0)
			waitpid(cmds->pid, &status, 0);
		cmds = cmds->next;
	}
	g_help.in_child = 0;
	if (pid > 0)
	{
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
		else if (WIFSIGNALED(status))
		{
			if (WTERMSIG(status) == SIGQUIT)
				return (131);
			else if (WTERMSIG(status) == SIGINT)
				return (130);
		}
	}
	return (1);
}

int	ft_pipe(t_cmd *lst, t_list **envl)
{
	t_pipe	var;

	ft_initialize(var.io, &var.new, lst, &var.k);
	while (lst->next)
	{
		pipe(var.fd);
		var.io[2] = var.fd[0];
		ft_redirect(lst->file, var.fd_io, 0, envl);
		if (g_help.in_here_doc == 254)
		{
			g_help.in_here_doc = 0;
			return (1);
		}
		ft_set_io(var.fd_io, var.io, var.fd[1]);
		ft_fork_pipe(var.io, lst->args, envl, &lst->pid);
		ft_pipe_help(var.fd, var.io, &var.k);
		lst = lst->next;
	}
	return (ft_pipe_last_cmd(var, lst, envl));
}
