/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:17:56 by framdani          #+#    #+#             */
/*   Updated: 2021/05/05 15:28:23 by framdani         ###   ########.fr       */
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

char		next_char(char *str)
{
	str++;
	return (*str);
}

t_token		*build_lexer(char *input)
{
	t_token		*lst_tok;
	int			state;
	char		*data;
	int			size;
	int			j;
	char		c;

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
			else if (*input == ESC_CHAR)
			{
				//check next char => if char skip don't store it
				c = next_char(input);
				if  (!c)
					add_token(&lst_tok, "ESCAPE", ESC_CHAR);
				else if (ft_strchr("<>|;$\"\'\\ ", c))
				{
					data = malloc(2);
					data[0]=c;
					data[1] = '\0';
					add_token(&lst_tok, data, CHAR);
					data = NULL;
					free(data);
					input++;
				}
				input++;
			}
			else if (*input == ';')
			{
				input++;
				add_token(&lst_tok, "SEMICOLON", SEMICOLON);
				input = skip_spaces(input);
			}
			else if (*input == '|')
			{
				input++;
				add_token(&lst_tok, "PIPE", PIPE);
				input = skip_spaces(input);
			}
			else if (*input == '<')
			{
				input++;
				add_token(&lst_tok, "LEFT", LEFT);
				input = skip_spaces(input);
			}
			else if (*input == '>')
			{
				input++;
				input = skip_spaces(input);
				if (*input == '>')
				{
					add_token(&lst_tok, "GREATER", GREATER);
					input++;
				}
				else
					add_token(&lst_tok, "RIGHT", RIGHT);
			}
			else if (*input == '$')
			{
				add_token(&lst_tok, "DOLLAR", DOLLAR);
				input++;
			}
			else if (*input == QUOTE)
			{
				state = IN_QUOTE;
				add_token(&lst_tok, "QUOTE", QUOTE);
				input++;
				break;
			}
			else if (*input == D_QUOTE)
			{
				state = IN_DQUOTE;
				add_token(&lst_tok, "DQUOTE", D_QUOTE);
				input++;
				break;
			}
			else
				//if (no_special_char(*input))
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
		while (state == IN_QUOTE && *input != '\0')
		{
			data = malloc(size);
			j = 0;
			while (*input != QUOTE && *input != '\0')
			{
				data[j] = *input;
				j++;
				input++;
			}
			data[j] = '\0';
			add_token(&lst_tok, data, CHAR);
			free(data);
			if (*input == QUOTE)
			{
				add_token(&lst_tok, "QUOTE", QUOTE);
				state = NORMAL;
				input++;
			}
		}
		while (state == IN_DQUOTE && *input)
		{
			if (*input != '\0' && *input == DOLLAR)
			{
				add_token(&lst_tok, "DOLLAR", DOLLAR);
				input++;
			}
			else if (*input == ESC_CHAR)
			{
				c = next_char(input);
				if (ft_strchr("$\"\\", c))
				{
					//printf(" --%s, -%c\n",ft_strchr("$\"\\", c), *input );
					data = malloc(2);
					data[0] = c;
					data[1] = '\0';
					add_token(&lst_tok, data, CHAR);
					data = NULL;
					free(data);
					input++;
				}
				else
				{
					data = malloc(2);
					data[0] = '\\';
					data[1] = '\0';
					add_token(&lst_tok, data, CHAR);
					free(data);
				}
				input++;
			}
			else if (*input != D_QUOTE && *input != DOLLAR
					&& *input != ESC_CHAR)
			{
				data = malloc(size);
				j = 0;
				while (*input != '\0' && *input != D_QUOTE && *input != DOLLAR
						&& *input != ESC_CHAR)
				{
					data[j] = *input;
					j++;
					input++;
				}
				data[j] = '\0';
				add_token(&lst_tok, data, CHAR);
				free(data);
			}
			if (*input != '\0' && *input == D_QUOTE)
			{
				state = NORMAL;
				add_token(&lst_tok, "DQUOTE", D_QUOTE);
				input++;
			}
		}
	}
	if (state == IN_QUOTE || state == IN_DQUOTE)
	{
		printf("Minishell : Syntax Error : Missing quote.\n");
		return (NULL);
	}
	//store each token with the exact type
	return (lst_tok);
}

/*
 * Escape character => it preserves  the literal value of the next char
 * example : echo "\"" => "
 *			echo "\$PATH" => $PATH
 *
 */

/*
 * Single quotes => preserves the LITERAL value of each character within the quotes.
 * A single quote may not occur between single quotes, even when preceded by a backslash.
 */

/*
 * Double quotes => preserves the literal value of all characters, with the exception of $
 * ` and \'
 *
 */

/*
 * if ESC_char at the end error
 */

//echo "$ "=> $
//echo "$1" => depends
//echo "$1kol">it's like echo "$1" "kol"
//
//"command" => command
