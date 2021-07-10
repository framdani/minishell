/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <framdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:51:26 by framdani          #+#    #+#             */
/*   Updated: 2021/07/10 15:49:08 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"
#include "../libft/libft.h"
#include "../includes/minishell.h"
#include <stdlib.h>

void	not_valid_id(char *id)
{
	ft_putstr_fd("minishell : '", 2);
	ft_putstr_fd(id, 2);
	ft_putstr_fd("' : not a valid identifier\n", 2);
}

void	print_error(char *str)
{
	ft_putstr_fd(str, 2);
}

void	print_error_and_exit(t_token **lst_tok, int error)
{
	g_help.ret = 258;
	free_lst_tokens(lst_tok);
	print_error("Minishell : syntax error ");
	if (error == 6)
		print_error("near unexpected token 'newline'\n");
	else if (error == 3)
		print_error("unexpected token after ';'\n");
	else if (error == 4)
		print_error("unexpected token after '<''\n");
	else if (error == 5)
		print_error("unexpected token after '>'\n");
	else if (error == 2)
		print_error("unexpected token after '|' \n");
	else if (error == 7)
		print_error("near unexpected token '|'\n");
	else if (error == 8)
		print_error("near unexpected token ';'\n");
	else
		print_error(" : Missing quote.\n");
}
