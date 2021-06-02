/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 05:48:18 by framdani          #+#    #+#             */
/*   Updated: 2019/10/25 05:54:09 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int r;

	if (n < 0)
	{
		r = n * -1;
		ft_putchar_fd('-', fd);
	}
	else
		r = n;
	if (r >= 10)
		ft_putnbr_fd(r / 10, fd);
	ft_putchar_fd((r % 10) + '0', fd);
}
