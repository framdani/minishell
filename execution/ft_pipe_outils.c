/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_outils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:13:25 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/01 12:15:06 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_initialize(int io[3], t_cmd	**new, t_cmd **lst, int *k)
{
	io[0] = 0;
	*new = *lst;
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
