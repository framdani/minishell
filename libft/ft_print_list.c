/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:10:25 by akhalidy          #+#    #+#             */
/*   Updated: 2021/06/08 18:30:07 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//maybe to delete
void	ft_print_list(t_list *lst)
{
	
	while(lst)
	{
		ft_putstr_fd(lst->env, 1);
		ft_putstr_fd("=", 1);
		ft_putstr_fd(lst->value, 1);
		ft_putstr_fd("\n", 1);
		lst = lst->next;
	}
}
