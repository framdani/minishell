/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 01:49:14 by framdani          #+#    #+#             */
/*   Updated: 2019/10/24 02:53:23 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	*tmp;
	int		i;
	char	c;

	i = 0;
	tmp = s;
	c = '\n';
	if (s)
	{
		while (*tmp)
		{
			tmp++;
			i++;
		}
		write(fd, s, i);
	}
	write(fd, &c, 1);
}
