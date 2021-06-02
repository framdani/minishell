/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:00:53 by framdani          #+#    #+#             */
/*   Updated: 2019/10/26 06:13:08 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *l;
	t_list *tmp;

	tmp = NULL;
	l = NULL;
	if (lst && del)
	{
		l = *lst;
		while (l)
		{
			tmp = l;
			l = l->next;
			del(tmp->content);
			free(tmp);
		}
		(*lst) = NULL;
	}
}
