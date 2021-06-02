/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 21:31:47 by framdani          #+#    #+#             */
/*   Updated: 2019/10/25 02:56:18 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_length(unsigned int n)
{
	int cmpt;

	cmpt = 0;
	while (n >= 10)
	{
		n = n / 10;
		cmpt++;
	}
	return (cmpt);
}

char		*ft_itoa(int n)
{
	unsigned int	nb;
	char			*tab;
	int				i;
	int				l;

	i = 0;
	l = 0;
	nb = n;
	if (n < 0)
	{
		l++;
		nb = n * -1;
	}
	l = l + ft_length(nb);
	if (!(tab = malloc(sizeof(char) * (l + 2))))
		return (NULL);
	if (n < 0)
		tab[i++] = '-';
	tab[l + 1] = '\0';
	while (l >= i)
	{
		tab[l--] = nb % 10 + 48;
		nb = nb / 10;
	}
	return (tab);
}
