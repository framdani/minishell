/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:07:58 by akhalidy          #+#    #+#             */
/*   Updated: 2021/06/26 17:05:39 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_arr_to_list(char **str)
{
	t_list	*lst;
	char	**split;
	int		i;

	i = 0;
	lst = NULL;
	while (str[i])
	{
		split = ft_split(str[i], '=');
		ft_lstadd_back(&lst, ft_lstnew(ft_strdup(split[0]), ft_strdup(split[1])));
		ft_free(split);
		i++;
	}
	return(lst);
}
