/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_delete_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 17:22:16 by akhalidy          #+#    #+#             */
/*   Updated: 2021/06/02 17:41:50 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_prev_node(t_list *lst, char *content)
{
	t_list	*prev;

	prev = NULL;
	while (lst)
	{
		if (!ft_strncmp(lst->env, content, ft_strlen(content)))
			return (prev);
		prev = lst;
		lst = lst->next;
	}
	return (NULL);
}

t_list	*ft_find_node(t_list *lst, char *content)
{
	t_list *tmp;

	tmp = lst;
	while (tmp)
	{
		if (!ft_strncmp(tmp->env, content, ft_strlen(content) + 1))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_delete_node(t_list **lst, char *env)
{
	t_list	*prev;
	t_list	*tmp;

	prev = ft_prev_node(*lst, env);
	if (prev)
	{
		tmp = prev->next;
		prev->next = tmp->next;
	}
	else
	{
		tmp = *lst;
		if (!ft_strncmp(tmp->env, env, ft_strlen(env)))
			*lst = tmp->next;
		else
			tmp = NULL;
	}
	ft_lstdelone(tmp, free);
}
