/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 05:19:23 by framdani          #+#    #+#             */
/*   Updated: 2021/07/03 17:09:11 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		length;
	int		i;
	char	*res;

	length = 0;
	i = 0;
	if (!s1 && s2)
		length = ft_strlen(s2);
	else if (!s2 && s1)
		length = ft_strlen(s1);
	else if (s1 && s2)
		length = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(length + 1);
	if (!res)
		return (res);
	if (s1)
		while (*s1 != '\0')
			res[i++] = *(char *)s1++;
	if (s2)
		while (*s2 != '\0')
			res[i++] = *(char *)s2++;
	res[i] = '\0';
	return (res);
}
