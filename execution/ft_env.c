/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:23:17 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/03 11:21:44 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_lst_print_fd(t_list	*head, int fd)
{
	while (head)
	{
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
	ft_lst_print_fd(envl, fd);
}
