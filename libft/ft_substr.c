/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 05:04:57 by framdani          #+#    #+#             */
/*   Updated: 2019/10/29 17:40:03 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start,
		size_t len)
{
	size_t			i;
	char			*tmp;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		len = 0;
	tmp = malloc(len + 1);
	if (!tmp)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		tmp[i] = '\0';
		return (tmp);
	}
	while (i < len && s[start + i])
	{
		tmp[i] = s[start + i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
