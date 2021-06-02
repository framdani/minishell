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

#include "includes/lexer.h"
#include "includes/minishell.h"
#include "libft/libft.h"

void 	expand_value(t_token **lst_tok,char *value)
{
	char 	*new_value;

	new_value = ft_strdup("");
	while (*value != '\0' && *value == 32)
		value++;
	while (*value != '\0')
	{
		while (*value != 32 && *value != '\0')
		{
			new_value = ft_charjoin(new_value, *value);
			value++;
		}
		add_token(lst_tok, new_value, CHAR);
		free(new_value);
		new_value = ft_strdup("");
		if (*value == 32)
		{
			while (*value == 32 && *value != '\0')
				value++;
			add_token(lst_tok, "SPACE", SPACE);
		}
	}
	free(new_value);
}

char	*expander(t_token **lst_token, char *input)
{
	char	*new_value;
	char	*token;

	new_value = ft_strdup("");
	if (ft_isdigit(*input))
	{
		input++;
		add_token(lst_token, "SPACE", SPACE);
	}
	else if (ft_isalpha(*input) || *input == '_')
	{
		while (ft_isalnum(*input) || *input == '_')
		{
			new_value = ft_charjoin(new_value, *input);
			input++;
		}
		token = getenv(new_value);
		if (token != NULL)
			//add_token(lst_token, token, CHAR);// a parser
			expand_value(lst_token, token);
		else
			add_token(lst_token, "SPACE", SPACE);
	}
	free(new_value);
	return (input);
}
