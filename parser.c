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

int		check_syntax_errors(t_token *lexer)
{
	t_token *tmp;

	tmp = lexer;
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
			if (tmp->next->type == PIPE || tmp->next->type == SEMICOLON)
				return (4);
		}
		else if (tmp->type == RIGHT)
		{
			if (tmp->next->type == PIPE || tmp->next->type == SEMICOLON)
				return (5);
		}
		tmp = tmp->next;
	}
	if (tmp->type == PIPE || tmp->type == LEFT || tmp->type == RIGHT)
		return (6);
	return (1);
}

void	parser(t_token *lexer)
{
	t_token *tmp;

	tmp = lexer;
	if (tmp != NULL)
	{
		if (check_syntax_errors(lexer) == 6)
			print_error("Minishell : syntax error near unexpected token 'newline'\n");
		else if (check_syntax_errors(lexer) == 3)
			print_error("Minishell : syntax error unexpected token after ';'\n");
		else if (check_syntax_errors(lexer) == 4)
			print_error("Minishell : syntax error unexpected token after <\n");
		else if (check_syntax_errors(lexer) == 5)
			print_error("Minishell : syntax error unexpected token after >\n");
		else if (check_syntax_errors(lexer) == 2)
			print_error("Minishell : syntax error unexpected token after | \n.");
	//; | last char
		else
			print_lexer(lexer);
	//check unexpected characters after |
	//check unexpected char ater ;
	//check unexpected char after \
	//check unexpected char after <
	//check unexpected char after >
	
}}
