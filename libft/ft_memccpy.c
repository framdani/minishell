/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:46:33 by framdani          #+#    #+#             */
/*   Updated: 2019/10/31 07:31:03 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	ch;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		if (d[i] == ch)
			return (d + i + 1);
		i++;
	}
	return (NULL);
}
