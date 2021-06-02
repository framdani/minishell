/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:33:54 by framdani          #+#    #+#             */
/*   Updated: 2019/10/25 01:28:20 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		cmpt;
	t_list	*tmp;

	cmpt = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		cmpt++;
		tmp = tmp->next;
	}
	return (cmpt);
}
