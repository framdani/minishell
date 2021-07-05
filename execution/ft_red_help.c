/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_red_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:50:12 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/05 21:30:19 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_close(int fd)
{
	if (fd >= 0)
		close(fd);
}

void	ft_rd_print_error(char *path, int option)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	if (option)
		exit (1);
}

void	reset_stds(void)
{
	dup2(g_help.std_in, STDIN_FILENO);
	dup2(g_help.std_out, STDOUT_FILENO);
}

void	ft_free_envv(t_list **env, t_envv **envv)
{
	if ((*envv)->value)
	{
		free((*env)->value);
		(*env)->value = (*envv)->value;
	}
	free((*envv)->name);
}
