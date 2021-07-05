/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:51:26 by framdani          #+#    #+#             */
/*   Updated: 2021/06/02 13:42:26 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"
#include "../libft/libft.h"
#include "../includes/minishell.h"
#include <stdlib.h>

void	print_error(char *str)
{
	ft_putstr_fd(str, 2);
}

void	print_error_and_exit(t_token **lst_tok, int error)
{
	g_help.ret = 258;
	printf("ret = %d \n", g_help.ret);
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
