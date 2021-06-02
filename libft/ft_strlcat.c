/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:17:39 by framdani          #+#    #+#             */
/*   Updated: 2019/10/31 08:19:06 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t k;

	k = 0;
	if (!dst && size == 0)
		return (ft_strlen(src));
	j = ft_strlen(dst);
	i = ft_strlen(src);
	if (size <= j)
		return (size + i);
	while (k < size - j - 1 && src[k] != '\0')
	{
		dst[k + j] = src[k];
		k++;
	}
	dst[k + j] = '\0';
	return (i + j);
}
