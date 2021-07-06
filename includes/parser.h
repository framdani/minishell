/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <framdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:27:45 by framdani          #+#    #+#             */
/*   Updated: 2021/07/05 17:53:52 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "lexer.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "lexer.h"
# include "../libft/libft.h"

# define INPUT = 0
# define OUTPUT = 1
typedef struct s_arg
{
	char				*value;
	struct s_arg		*next;
}						t_arg;

typedef struct s_file
{
	char				*filename;
	int					type;
	struct s_file		*next;
}						t_file;

typedef struct s_envv
{
	char	*name;
	char	*value;
}			t_envv;

typedef struct s_cmd
{
	char				**args;
	t_file				*file;
	int					pid;
	struct s_cmd		*next;
}						t_cmd;

void	not_valid_id(char *id);
int		ft_lst_size(t_arg	*lst_arg);
char	*parse_line_hd(char *input, t_list **envl);
t_token	*parser(t_token *lexer);
char	*expander(t_token **lst, char *input, t_list **envl, int state);
char	*expander_inside_dquote(t_token **lst_token, char *input, t_list **envl,
			int state);
char	*expander_spec_case(t_token **lst_token, char *input, t_list **envl);
void	print_error_and_exit(t_token **lst_token, int error);
t_cmd	*fill_struct(t_token *token);
void	add_arg(t_arg **lst_arg, char *arg);
void	add_cmd(t_cmd **lst_cmds, t_arg **args, t_file **files);
void	add_file(t_file **lst_files, char *filename, int type);
void	print_struct(t_cmd *lst_cmnds);
char	**convert_into_dpointer(t_arg **lst_arg);
void	free_lst_files(t_file **lst_files);
void	free_lst_args(t_arg **lst_args);
void	free_lst_cmds(t_cmd **lst_cmds);
int		is_redirection(int type);
t_envv	*get_key_value(char	*arg);
void	print_error(char *str);
#endif
