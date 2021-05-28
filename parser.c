/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:29:37 by framdani          #+#    #+#             */
/*   Updated: 2021/05/21 16:29:48 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include "includes/lexer.h"
#include "libft/libft.h"
#include <stdlib.h>

/*
 *check_first_token(type)
 */


/*
 * check_last_token(type)
 */

int		check_syntax_errors(t_token *lexer)
{
	t_token *tmp;

	tmp = lexer;
	if (lexer->type == PIPE)
		return (7);
	else if (lexer->type == SEMICOLON)
		return(8);
	while (tmp->next != NULL)
	{
		if (tmp->type == PIPE)
		{
			if (tmp->next->type == SEMICOLON || tmp->next->type == PIPE ||
					tmp->next->type == LEFT || tmp->next->type == RIGHT)
				return (2);
		}
		else if (tmp->type == SEMICOLON)
		{
			if (tmp->next->type == SEMICOLON || tmp->next->type == PIPE ||
					tmp->next->type == LEFT || tmp->next->type == RIGHT)
				return (3);
		}
		else if (tmp->type == LEFT)
		{
			if (tmp->next->type == PIPE || tmp->next->type == SEMICOLON ||
					tmp->next->type == LEFT)
				return (4);
			if (tmp->next->type == SPACE && tmp->next->next->type == RIGHT)
				return (5);
		}
		else if (tmp->type == RIGHT)
		{
			if (tmp->next->type == PIPE || tmp->next->type == SEMICOLON ||
					tmp->next->type == LEFT || tmp->next->type == GREATER ||
					tmp->next->type == RIGHT)
				return (5);
		}
		else if (tmp->type == GREATER)
		{
			if (tmp->next->type == PIPE || tmp->next->type == SEMICOLON ||
					tmp->next->type == LEFT || tmp->next->type == RIGHT)
				return (5);
		}
		tmp = tmp->next;
	}
	if (tmp->type == PIPE || tmp->type == LEFT || tmp->type == RIGHT || tmp->type == ESC_CHAR)
		return (6);
	return (1);
}

void	parser(t_token *lexer)
{
	t_token *tmp;
	int		id_error;

	tmp = lexer;
	id_error = 1;
	if (tmp != NULL)
	{
		id_error = check_syntax_errors(lexer);
		if (id_error != 1)
			print_error_and_exit(&lexer, id_error);
	}
}
