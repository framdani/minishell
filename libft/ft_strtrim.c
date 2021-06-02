/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 04:16:16 by framdani          #+#    #+#             */
/*   Updated: 2019/10/30 01:01:56 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	start(const char *s, const char *set)
{
	int i;
	int j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (set[j])
		{
			if (s[i] == set[j])
				break ;
			j++;
		}
		if (set[j] == '\0')
			break ;
		i++;
	}
	return (i);
}

static int	end(const char *s, const char *set)
{
	int i;
	int j;
	int k;

	i = start(s, set);
	k = ft_strlen(s);
	k--;
	while (k >= i)
	{
		j = 0;
		while (set[j])
		{
			if (s[k] == set[j])
				break ;
			j++;
		}
		if (set[j] == '\0')
			break ;
		k--;
	}
	return (k);
}

char		*ft_strtrim(const char *s, const char *set)
{
	char	*str;
	int		i;
	int		k;

	if (!s || !set)
		return (NULL);
	k = end(s, set);
	i = start(s, set);
	if (!(str = (char*)malloc(k - i + 2)))
		return (NULL);
	str = ft_substr(s, i, k - i + 1);
	return (str);
}
