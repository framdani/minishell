/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 02:32:35 by framdani          #+#    #+#             */
/*   Updated: 2019/10/31 07:30:12 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	si;

	si = count * size;
	if (!(ptr = (char*)malloc(si)))
		return (NULL);
	ft_bzero(ptr, si);
	return (ptr);
}
