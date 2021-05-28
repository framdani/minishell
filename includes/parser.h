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
	t_cmd				*cmds;
	int					nbr_pipe; // cmds
}						t_pipe_sequence;

void 	parser(t_token *lexer);
char	*expander(t_token **lst, char *input);
void	print_error_and_exit(t_token **lst_token, int error);
void	fill_struct_and_execute(t_token *token);
void	add_arg(t_arg **lst_arg, char *arg);
void	add_cmd(t_cmd **lst_cmds, t_arg **args, t_file **files);
void	add_file(t_file **lst_files, char *filename, int type);
void	print_struct(t_cmd *lst_cmnds);
t_cmd	init_cmd(void);
t_file	init_file(void);
t_arg	init_args(void);
#endif
