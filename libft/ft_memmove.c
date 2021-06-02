/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:53:20 by framdani          #+#    #+#             */
/*   Updated: 2019/10/31 02:03:04 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	d = (char *)dst;
	s = (char *)src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (len == 0)
		return (dst);
	if (src < dst)
	{
		while (len)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
		return (dst);
	}
	else
		ft_memcpy(d, s, len);
	return (dst);
}
