/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:09:06 by framdani          #+#    #+#             */
/*   Updated: 2021/04/16 14:09:39 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include "../libft/libft.h"
#include "lexer.h"
#include "parser.h"

void	print_error(char *str);
t_pipe_sequence *new_pipe_sequence(t_token *lexer);
#endif
