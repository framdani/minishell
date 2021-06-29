/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:07:12 by akhalidy          #+#    #+#             */
/*   Updated: 2021/06/29 17:30:45 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_list_to_arr(t_list *lst)
{
	t_list	*tmp;
	char	**str;
	char	*pfree;
	int		i;

	i = 0;
	tmp = lst;
	str = (char **)malloc((ft_lstsize(lst) + 1) * sizeof(char *));
	while(tmp)
	{
		str[i] = ft_strjoin(tmp->env, "=");
		pfree = str[i];
		str[i] = ft_strjoin(str[i], tmp->value);
		free(pfree);
		tmp = tmp->next;
		i++;
	}
	str[i] = NULL;
	return(str);
}
