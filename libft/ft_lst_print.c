/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 18:27:37 by akhalidy          #+#    #+#             */
/*   Updated: 2021/06/02 18:04:39 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_print_fd(t_list	*head, int fd)
{
	while(head)
	{
		if (head->value) //&& *(head->value))
		{
			ft_putstr_fd(head->env, fd);
			ft_putstr_fd("=", fd);
			ft_putstr_fd(head->value, fd);
			ft_putstr_fd("\n", fd);
		}
		head = head->next;
	}
}
