/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:15:24 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/03 17:10:07 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a > b)
		return (b);
	return (a);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	i;
	int	l;
	int	max;

	if (!dst && size == 0)
		return (ft_strlen(src));
	l = (int)ft_strlen(dst);
	max = (int)size - l - 1;
	i = 0;
	while (src[i] && i < max)
	{
		dst[l + i] = src[i];
		i++;
	}
	if (max > 0)
		dst[l + i] = '\0';
	return (ft_min((size_t)l, size) + ft_strlen(src));
}
