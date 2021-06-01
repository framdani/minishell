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

#include "includes/lexer.h"
#include "includes/minishell.h"
#include "libft/libft.h"

void		add_token(t_token **lst_tok, char *data, int type)
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

t_token		*lexer(char *input)
{
	t_token		*lst_tok;
	int			state;
	int			size;
	t_info		info;

	lst_tok = NULL;
	state = NORMAL;
	size = ft_strlen(input) + 1;
	input = skip_spaces(input);
	while (*input != '\0')
	{
		while (state == NORMAL && *input != '\0')
		{
			info = tokenize_state_normal(input, &lst_tok, size);
			state = info.state;
			input = info.input;
		}
		while (state == IN_QUOTE && *input != '\0')
		{
			info = tokenize_inside_squote(input, &lst_tok, size);
			state = info.state;
			input = info.input;
		}
		while (state == IN_DQUOTE && *input != '\0')
		{
			info = tokenize_inside_dquote(input, &lst_tok, size);
			state = info.state;
			input = info.input;

		}
	}
	if (state == IN_QUOTE || state == IN_DQUOTE)
	{
		printf("Minishell : Syntax Error : Missing quote.\n");
		free_token(&lst_tok);
		return (NULL);
	}
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
