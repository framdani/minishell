/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:57:03 by framdani          #+#    #+#             */
/*   Updated: 2021/06/30 14:57:23 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"
#include "../libft/libft.h"

char	*skip_spaces(char *str)
{
	while (*str != '\0' && (*str == 32 || *str == '\t'))
		str++;
	return (str);
}

char	next_char(char *str)
{
	str++;
	return (*str);
}
