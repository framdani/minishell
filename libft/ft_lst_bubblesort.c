/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_bubblesort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:28:00 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/03 17:01:26 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap_str(char **str1, char **str2)
{
	char	*tmp;

	tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
}

void	ft_lstbubblesort(t_list	*lst)
{
	int		i;
	int		j;
	int		n;
	t_list	*head;

	i = 0;
	head = lst;
	n = ft_lstsize(lst);
	while (i < n - 1)
	{
		j = 0;
		lst = head;
		while (j < n - i - 1)
		{
			if (ft_strncmp(lst->env, lst->next->env, ft_strlen(lst->env)) > 0)
			{
				ft_swap_str(&(lst->env), &(lst->next->env));
				ft_swap_str(&(lst->value), &(lst->next->value));
			}
			lst = lst->next;
			j++;
		}
		i++;
	}
}
