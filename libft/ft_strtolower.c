/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:04:30 by akhalidy          #+#    #+#             */
/*   Updated: 2021/06/08 18:30:01 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strtolower(char **str)
{
	int	i;

	i = -1;
	while ((*str)[++i])
	//  str[0][i] = ft_tolower(str[0][i]);
		*(*str + i) = ft_tolower(*(*str + i));
}
