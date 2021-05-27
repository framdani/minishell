/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:27:45 by framdani          #+#    #+#             */
/*   Updated: 2021/05/24 17:29:51 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
#include "lexer.h"

# define INPUT = 0
# define OUTPUT = 1
/* List of args = SUFFIX
 *
 * option
 * simple arg
 * redirection filename
 *
 * */
typedef struct			s_arg
{
	char				*value;
	struct s_arg		*next;
}						t_arg;

typedef struct			s_file
{
	char				*filename;
	int					type;
	struct s_file		*next;
}						t_file;
/*
 * cmd name is the first arg
 * linked_list of args
 * nbr_args = size of t_args
 *
 */

typedef struct			s_cmd
{
	char				*name;
	t_arg				*args;
	t_file				*file;
	int					nbr_args;
	struct s_cmd		*next;
}						t_cmd;

/*
 * Pipe sequence : simple commands
 *	              |pipe sequence
 *	Linked list of commands
 *  number of commands = size of t_cmd
 *
 */

typedef struct			s_pipe_sequence
{
	t_cmd				cmds;
	int					nbr_pipe; // cmds
}						t_pipe_sequence;

void 	parser(t_token *lexer);
char	*expander(t_token **lst, char *input);
#endif
