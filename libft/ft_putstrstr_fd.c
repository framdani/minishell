/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrstr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:11:47 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/03 17:06:44 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//maybe to delete
void	ft_putstrstr_fd(char **str, int fd)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = str;
	while (*tmp)
	{
		ft_putstr_fd(*tmp, fd);
		ft_putstr_fd("\n", fd);
		tmp++;
	}
}
