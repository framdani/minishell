/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 03:35:19 by akhalidy          #+#    #+#             */
/*   Updated: 2019/10/23 04:00:11 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!(str = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (i < len)
	{
		str[i] = f((unsigned int)i, ((char*)s)[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
