/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:20:33 by akhalidy          #+#    #+#             */
/*   Updated: 2019/10/19 23:35:26 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	int		n;
	int		r;
	int		k;

	ptr = malloc(count * size);
	if (ptr)
	{
		n = count * size / sizeof(long);
		r = count * size % sizeof(long);
		k = 0;
		while (n--)
			((long *)ptr)[k++] = 0;
		while (r--)
			((char *)ptr)[k * sizeof(long) + r] = 0;
		return (ptr);
	}
	return (NULL);
}
