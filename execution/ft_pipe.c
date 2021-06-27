/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:32:49 by akhalidy          #+#    #+#             */
/*   Updated: 2021/06/25 18:58:06 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//You should implement a proper funtion that traites all the cases!

void	ft_exit_child(void)
{
	if (errno == 13 || errno == 21)
		exit(126);
	if (errno == 2)
		exit(127);
}

void	ft_fork_pipe(int *io, char **args, t_list *envl, int *pid)
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
		if(io[2] != -18)
			close(io[2]);
		ft_launch_exec(args, envl, 0);
		ft_exit_child();
	}
	if (io[0] != 0)
		close(io[0]);
	if (io[1] != 1)
		close(io[1]);
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

int	ft_wait_loop(t_cmd	*cmds)
{
	int	status;

	while (cmds)
	{
		if (cmds->pid > 0)
			waitpid(cmds->pid, &status, 0);
		cmds = cmds->next;
	}
	return (WEXITSTATUS(status));
}

int	ft_pipe(t_cmd *lst, t_list *envl)
{
	int		fd[2];
	int		io[3];
	// int		status;
	t_cmd	*new;
	int		k;
	int		fd_io[2];

	io[0] = 0;
	new = lst;
	io[2] = -18;
	k = 0;
	while (lst->next)
	{
		pipe(fd);
		io[2] = fd[0];
		ft_redirect(lst->file, &fd_io[0], &fd_io[1], 1);
		ft_set_io(fd_io, io, fd[1]);
		ft_fork_pipe(io, lst->args, envl, &lst->pid);
		close(fd[1]);
		// if (k)
		// {
		// 	ft_putendl_fd("GOT HERE", 2);
		// 	close(fd[0]);
		// }
		if (!k)
			k = 1;
		io[0] = io[2];
		lst = lst->next;
	}
	ft_redirect(lst->file, &fd_io[0], &fd_io[1], 1);
	ft_set_io(fd_io, io, 1);
	ft_fork_pipe(io, lst->args, envl, &lst->pid);
	if (k)
	{
		// ft_putendl_fd("GOT HERE222", 2);
		close(fd[0]);
	}
	return (ft_wait_loop(new));
	// while (new)
	// {
	// 	waitpid(lst->pid, &status, 0);
	// 	new = new->next;
	// }
}
