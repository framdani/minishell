/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 12:16:06 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/09 17:46:43 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

void	ft_here_doc(int *fd_in, t_file *lst, t_list **env)
{
	int		tmp;
	char	*line;
	int		fd;
	int		pid;
	int		status;

	g_help.in_here_doc = 1;
	g_help.in_child = 1;
	pid = fork();
	if (!pid)
	{
		ft_her_doc_help(lst, env);
		exit (0);
	}
	waitpid(pid, &status, 0);
	ft_close(*fd_in);
	g_help.in_here_doc = WEXITSTATUS(status);
	*fd_in = open("/tmp/file", O_RDONLY);
	g_help.in_child = 0;
}

int	ft_open_fil_read(int *fd_in, int *fd_out, t_file *lst, int option)
{
	int		tmp;

	tmp = *fd_in;
	*fd_in = open(lst->filename, O_RDONLY);
	if (*fd_in == -1)
	{
		ft_close(tmp);
		ft_close(*fd_out);
		ft_rd_print_error(lst->filename, option);
		return (0);
	}
	ft_close(tmp);
	return (1);
}

int	ft_open_fil_write(int *fd_in, int *fd_out, t_file *lst, int option)
{
	int		tmp;

	tmp = *fd_out;
	if (lst->type == 1)
		*fd_out = open(lst->filename, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	else
		*fd_out = open(lst->filename, O_CREAT | O_APPEND | O_WRONLY, 0644);
	if (*fd_out == -1)
	{
		ft_close(tmp);
		ft_close(*fd_in);
		ft_rd_print_error(lst->filename, option);
		return (0);
	}
	ft_close(tmp);
	return (1);
}

int	ft_redirect(t_file *fil_lst, int fd[2], int option, t_list **env)
{
	t_file	*lst;
	int		ret;

	fd[0] = -18;
	fd[1] = -18;
	lst = fil_lst;
	ret = 1;
	if (!lst)
		return (-1);
	while (lst)
	{
		if (!lst->type)
			ret = ft_open_fil_read(&fd[0], &fd[1], lst, option);
		else if (lst->type == 3)
			ft_here_doc(&fd[0], lst, env);
		else
			ret = ft_open_fil_write(&fd[0], &fd[1], lst, option);
		if (!ret)
			return (ret);
		lst = lst->next;
	}
	return (1);
}
