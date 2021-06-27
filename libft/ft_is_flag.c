/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_one_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:53:46 by akhalidy          #+#    #+#             */
/*   Updated: 2021/06/08 18:35:08 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//is_flag
int ft_is_flag(char *str, char c)
{
    int i;
    
    i = -1;
    if (!str)
        return(-1);
    while (str[++i])
    {
        if (str[i] != c)
            return(1);
    }
    return(0);
}
