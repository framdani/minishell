/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:32:49 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/03 19:20:24 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_exit_child(void)
{
	if (errno == 13 || errno == 21)
		exit(126);
	if (errno == 2)
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

	while (cmds)
	{
		pid = cmds->pid;
		if (cmds->pid > 0)
			waitpid(cmds->pid, &status, 0);
		cmds = cmds->next;
	}
	if (pid > 0)
		return (WEXITSTATUS(status));
	return (1);
}

int	ft_pipe(t_cmd *lst, t_list **envl)
{
	int		fd[2];
	int		io[3];
	t_cmd	*new;
	int		k;
	int		fd_io[2];

	ft_initialize(io, &new, &lst, &k);
	while (lst->next)
	{
		pipe(fd);
		io[2] = fd[0];
		ft_redirect(lst->file, fd_io, 0, envl);
		ft_set_io(fd_io, io, fd[1]);
		ft_fork_pipe(io, lst->args, envl, &lst->pid);
		ft_pipe_help(fd, io, &k);
		lst = lst->next;
	}
	ft_redirect(lst->file, fd_io, 0, envl);
	ft_set_io(fd_io, io, 1);
	ft_fork_pipe(io, lst->args, envl, &lst->pid);
	if (k)
		close(fd[0]);
	return (ft_wait_loop(new));
}
