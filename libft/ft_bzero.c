/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:32:12 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/03 16:52:20 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int	t;
	int	r;
	int	k;

	if (n)
	{
		t = n / sizeof(long);
		r = n % sizeof(long);
		k = 0;
		while (t--)
			((long *)s)[k++] = 0;
		while (r--)
			((char *)s)[k * sizeof(long) + r] = 0;
	}
}
