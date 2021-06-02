/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:15:57 by framdani          #+#    #+#             */
/*   Updated: 2019/10/31 01:24:50 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ss;
	int		i;
	char	cc;

	i = 0;
	ss = (char *)s;
	cc = (char)c;
	while (ss[i] != cc)
	{
		if (ss[i] == '\0')
			return (NULL);
		i++;
	}
	return (ss + i);
}
