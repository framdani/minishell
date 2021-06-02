/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:02:50 by framdani          #+#    #+#             */
/*   Updated: 2019/10/31 01:13:39 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	char			*b;

	b = (char*)s;
	i = 0;
	while (i < n)
	{
		if (b[i] == c)
			return (b + i);
		i++;
	}
	return (NULL);
}
