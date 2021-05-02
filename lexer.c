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

static void		add_token(t_token **lst_tok, char *data, int type)
{
	t_token *new;
	t_token *tmp;

	new = malloc(sizeof(t_token));
	if (new != NULL)
	{
		new->next = NULL;
		new->value = ft_strdup(data);
		new->type = type;
		if (*lst_tok == NULL)
			*lst_tok = new;
		else
		{
			tmp = *lst_tok;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
}

char	*skip_spaces(char *str)
{
	while (*str != '\0' && (*str == 32 || *str == '\t'))
		str++;
	return (str);
}

t_token		*build_lexer(char *input)
{
	t_token		*lst_tok;
	int			state;
	char		*data;
	int			size;
	int			j;

	lst_tok = NULL;
	state = NORMAL;
	j = 0;
	size = ft_strlen(input) + 1;
	input = skip_spaces(input);
	while (*input != '\0')
	{
		while (state == NORMAL && *input != '\0')
		{
			if (*input == ' ' || *input == '\t')
			{
				input = skip_spaces(input);
				add_token(&lst_tok, "SPACE", SPACE);
			}
			else if (*input == ';')
			{
				add_token(&lst_tok, "SEMICOLON", SEMICOLON);
				input++;
			}
			else if (*input == '|')
			{
				add_token(&lst_tok, "PIPE", PIPE);
				input++;
			}
			else if (*input == '<')
			{
				add_token(&lst_tok, "LEFT", LEFT);
				input++;
			}
			else if (*input == '>')
			{
				add_token(&lst_tok, "RIGHT", RIGHT);
				input++;
			}
			else if (*input == '$')
			{
				add_token(&lst_tok, "DOLLAR", DOLLAR);
			}
			else if (*input == IN_QUOTE)
			{
				state = IN_QUOTE;
				break;
			}
			else if (*input == IN_DQUOTE)
			{
				state = IN_DQUOTE;
				break;
			}
			else if (no_special_char(*input))
			{
				data = malloc(size);
				j = 0;
				while (*input != '\0' && no_special_char(*input))
				{
					data[j] = *input;
					j++;
					input++;
				}
				data[j] = '\0';
				add_token(&lst_tok, data, CHAR);
				free(data);
			}
		}
		input++;
		//else if (state == IN_QUOTE)
		//else if (state == IN_DQUOTE)
	}
	print_lexer(lst_tok);
	//store each token with the exact type
	return (lst_tok);
}
