/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:17:56 by framdani          #+#    #+#             */
/*   Updated: 2021/05/01 14:38:55 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include "includes/lexer.h"
#include "libft/libft.h"
#include <stdlib.h>

static t_token		*new_token(char *data, int type)
{
	t_token		*token;

	if (!(token = malloc(sizeof(t_token))))
		return (NULL);
	token->value = ft_strdup(data);
	token->type = type;
	token->next = NULL;
	return (token);
}

static void		add_token(t_token **lst_tok, t_token *token)
{
	t_token *tmp;
	if (lst_tok && token)
	{
		tmp = (*lst_tok);
		if (!tmp)
			*lst_tok = token;
		else
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = token;
		}
	}
}

/*
 *detect_type_char()
 */

char	*skip_spaces(char **str)
{
	while (**str != '\0' && (**str == 32 || **str == '\t'))
		(*str)++;
	return (*str);
}

t_token		*build_lexer(char *input)
{
	t_token		*lst_tok;
	int			state;
	char		*data;
	int			j;
	t_token		*tok;
	int			l;

	l = ft_strlen(input) + 1;
	lst_tok = NULL;
	state = NORMAL;
	j = 0;
	skip_spaces(&input);
	while (*input != '\0')
	{
		while (state == NORMAL && *input != '\0')
		{
			if (*input == SEMICOLON)
			{
				tok = new_token(";", SEMICOLON);
				add_token(&lst_tok, tok);
				input++;
			}
			else if (*input == SPACE || *input == '\t')
			{
				skip_spaces(&input);
				add_token(&lst_tok, new_token(" ", SPACE));
			}
			else if (ft_isalnum(*input))
			{
				data = malloc()
				j = 0;
				while (*input != '\0' && ft_isalnum(*input))
				{
					data[j] = *input;
					j++;
					input++;
				}
				data[j] = '\0';
				add_token(&lst_tok, new_token(data, CHAR));
				free(data);
				data = NULL;
			}
			else if (*input == IN_QUOTE)
				state = IN_QUOTE;
			else if (*input == IN_DQUOTE)
				state = IN_DQUOTE;
		}
		//else if (state == IN_QUOTE)
		//else if (state == IN_DQUOTE)
	}
	print_lexer(lst_tok);
	//store each token with the exact type
	return (lst_tok);
}
