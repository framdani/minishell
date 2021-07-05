/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:23:17 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/05 21:54:55 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_lst_print_fd(t_list	*head, int fd)
{
	while (head)
	{
		if (!ft_strncmp(head->env, "PWD", 4) && !g_help.on_pwd)
		{
			head = head->next;
			continue ;
		}
		else if (!ft_strncmp(head->env, "OLDPWD", 7) && !g_help.on_oldpwd)
		{
			head = head->next;
			continue ;
		}
		if (head->value)
		{
			ft_putstr_fd(head->env, fd);
			ft_putstr_fd("=", fd);
			ft_putstr_fd(head->value, fd);
			ft_putstr_fd("\n", fd);
		}
		head = head->next;
	}
}

void	ft_env(t_list *envl, int fd)
{
	g_help.ret = 0;
	ft_lst_print_fd(envl, fd);
}
