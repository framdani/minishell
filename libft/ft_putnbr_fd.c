/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 06:33:22 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/03 17:05:05 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	m;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		m = -n;
	}
	else
		m = n;
	if (m >= 10)
	{
		ft_putnbr_fd(m / 10, fd);
		ft_putchar_fd(m % 10 + '0', fd);
	}
	if (m < 10)
		ft_putchar_fd(m % 10 + '0', fd);
}
