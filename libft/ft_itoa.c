/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:30:20 by akhalidy          #+#    #+#             */
/*   Updated: 2019/10/29 22:47:23 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		numlen(unsigned int n)
{
	unsigned int i;

	i = 0;
	if (!n)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char			*str;
	unsigned int	x;
	int				len;
	int				sign;

	sign = 0;
	if (n < 0)
	{
		sign++;
		x = -n;
	}
	else
		x = n;
	len = numlen(x) + sign + 1;
	if (!(str = (char *)ft_calloc(len ,sizeof(char))))
		return (NULL);
	len--;
	while (--len > 0 || (len == 0 && !sign))
	{
		str[len] = (x % 10) + '0';
		x = x / 10;
	}
	if (sign)
		str[len] = '-';
	return (str);
}
