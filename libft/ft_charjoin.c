/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:04:13 by framdani          #+#    #+#             */
/*   Updated: 2021/07/03 16:53:26 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char 	*ft_charjoin(char 	*str, char c)
{
	int		length;
	int		i;
	char	*res;

	length = 0;
	i = 0;
	if (str)
		length = ft_strlen(str);
	res = malloc(length + 2);
	if (!res)
		return (NULL);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = c;
	res[i + 1] = '\0';
	free(str);
	return (res);
}
