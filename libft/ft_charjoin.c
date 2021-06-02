/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:04:13 by framdani          #+#    #+#             */
/*   Updated: 2021/05/26 16:08:47 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char 	*ft_charjoin(char 	*str, char c)
{
	int 	length;
	int 	i;
	char 	*res;

	length = 0;
	i = 0;
	if (str)
		length = ft_strlen(str);
	if (!(res = malloc(length + 2)))
		return (NULL);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = c;
	res[i + 1] = '\0';
	return (res);
}
