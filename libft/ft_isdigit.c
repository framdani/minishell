/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:14:22 by akhalidy          #+#    #+#             */
/*   Updated: 2021/01/12 12:12:10 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isnumber(char *s, int *signe)
{
	int i;
	int dot;

	i = 0;
	dot = 0;
	*signe = 0;
	while (s[i] && ((s[i] >= 8 && s[i] <= 13) || s[i] == 32))
		i++;
	if (s[i] == '-')
	{
		(*signe)++;
		i++;
	}
	while (s[i])
	{
		if (s[i] == '.')
			dot++;
		else if (!ft_isdigit(s[i]) || dot > 1 || *signe > 1)
			return (0);
		i++;
	}
	return (1);
}

int	ft_char_frequency(char c, char *s)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] == c)
			n++;
		i++;
	}
	return (n);
}

int	ft_is_integer(char *s, int *signe)
{
	int i;

	i = 0;
	*signe = 0;
	while (s[i] && ((s[i] >= 8 && s[i] <= 13) || s[i] == 32))
		i++;
	if (s[i] == '-')
	{
		(*signe)++;
		i++;
	}
	while (s[i])
	{
		if (!ft_isdigit(s[i]) || *signe > 1)
			return (0);
		i++;
	}
	return (1);
}
