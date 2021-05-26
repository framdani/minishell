/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:47:40 by framdani          #+#    #+#             */
/*   Updated: 2021/05/26 15:47:43 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include "includes/lexer.h"
#include "libft/libft.h"
#include <stdlib.h>

char		*expander(t_token **lst_token,char *input)
{
	char	*new_value;
	char	*token;

	new_value = ft_strdup("");
	if (ft_isdigit(*input))
		input++;
	else if (ft_isalpha(*input) || *input == '_')
	{
		while (ft_isalnum(*input) || *input == '_')
		{
			new_value = ft_charjoin(new_value, *input);
			input++;
		}
		token = getenv(new_value);
		if (token)
			add_token(lst_token, token, CHAR);
	}
	return (input);
}
