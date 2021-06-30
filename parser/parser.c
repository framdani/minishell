/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:29:37 by framdani          #+#    #+#             */
/*   Updated: 2021/06/02 12:12:36 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"
#include "../libft/libft.h"

int	is_redirection(int type)
{
	if (type == LEFT || type == RIGHT || type == GREATER || type == LESSER)
		return (1);
	return (0);
}

int	unexpected_next_token(int current, int next)
{
	if (current == PIPE && next == PIPE)
		return (2);
	else if (current == LEFT)
	{
		if (next == PIPE || next == LEFT)
			return (4);
	}
	else if (current == RIGHT)
	{
		if (next == PIPE || next == LEFT
			|| next == GREATER)
			return (5);
	}
	else if (current == GREATER)
	{
		if (next == PIPE || is_redirection(next))
			return (5);
	}
	else if (current == LESSER)
	{
		if (next == PIPE || is_redirection(next))
			return (4);
	}
	return (0);
}

int	check_syntax_errors(t_token *lexer)
{
	t_token	*tmp;

	tmp = lexer;
	if (lexer->type == PIPE)
		return (7);
	while (tmp->next != NULL)
	{
		if (unexpected_next_token(tmp->type, tmp->next->type))
			return (unexpected_next_token(tmp->type, tmp->next->type));
		tmp = tmp->next;
	}
	if (tmp->type == PIPE || is_redirection(tmp->type))
		return (6);
	return (1);
}

t_token	*parser(t_token *lexer)
{
	t_token	*tmp;
	int		id_error;

	tmp = lexer;
	id_error = 1;
	if (tmp != NULL)
	{
		id_error = check_syntax_errors(lexer);
		if (id_error != 1)
		{
			print_error_and_exit(&lexer, id_error);
			return (NULL);
		}
	}
	return (lexer);
}
