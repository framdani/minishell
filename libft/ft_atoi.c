/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 05:34:05 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/03 17:38:30 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_ternary_operator(int signe)
{
	if (signe < 0)
		return (0);
	return (-1);
}

int	ft_atoi(const char *str)
{
	char			*s;
	int				signe;
	unsigned long	x;

	s = (char *)str;
	signe = 1;
	x = 0;
	while ((*s >= 8 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-')
	{
		signe = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		x = x * 10 + (*s - '0');
		s++;
		if (x > 9223372036854775807)
			return (ft_ternary_operator(signe));
	}
	return (signe * x);
}
