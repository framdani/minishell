/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 06:56:01 by akhalidy          #+#    #+#             */
/*   Updated: 2019/10/30 04:21:06 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char			*s;
	unsigned int	start;
	unsigned int	end;
	unsigned int	size;
	unsigned int	len;

	if (!s1 || !set)
		return (NULL);
	if (!*s1)
		return (ft_strdup(s1));
	start = 0;
	end = 0;
	len = ft_strlen(s1);
	while (ft_isinset(s1[start], (char *)set) && s1[start])
		start++;
	while (ft_isinset(s1[len - 1], (char *)set) && len && len-- > start)
		end++;
	size = ft_strlen(s1) - (start + end);
	s = ft_substr(s1, start, size);
	return (s);
}
