/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:58:06 by framdani          #+#    #+#             */
/*   Updated: 2019/10/31 08:16:36 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;
	char	*to_find;

	str = (char*)haystack;
	to_find = (char*)needle;
	if (*to_find == '\0' || (str == NULL && len == 0))
		return (str);
	i = 0;
	j = 0;
	while (*(str + i) != '\0' && i < len)
	{
		while (*(str + i + j) == *(to_find + j) &&
				*(str + i + j) != '\0' && i + j < len)
			j++;
		if (*(to_find + j) == '\0')
			return (str + i);
		i++;
		if (*(str + i) == '\0' || i == len)
			return (NULL);
		j = 0;
	}
	return (NULL);
}
