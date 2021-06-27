/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:07:12 by akhalidy          #+#    #+#             */
/*   Updated: 2021/06/08 20:34:27 by akhalidy         ###   ########.fr       */
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
	while(lst)
	{
		// pfree = ft_strdup(lst->env);
		// str2 = ft_strdup(lst->value);
		str[i] = ft_strjoin(lst->env, "=");
		// free(pfree);
		pfree = str[i];
		str[i] = ft_strjoin(str[i], lst->value);
		free(pfree);
		// free(str2);
		lst = lst->next;
		i++;
	}
	str[i] = NULL;
	return(str);
}
