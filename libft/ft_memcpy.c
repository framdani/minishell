/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:40:22 by framdani          #+#    #+#             */
/*   Updated: 2019/10/31 07:31:20 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	char		*s;
	size_t		i;

	s = (char *)src;
	d = (char *)dest;
	i = 0;
	if (!d && !s)
		return (NULL);
	if (d == s)
		return (unsigned char*)(dest);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (unsigned char*)(dest);
}
