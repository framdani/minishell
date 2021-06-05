/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:20:32 by framdani          #+#    #+#             */
/*   Updated: 2021/04/30 16:53:12 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
#define LEXER_H
# define NORMAL 1
# define IN_QUOTE 2
# define IN_DQUOTE 3

/*
 * Define Token Types
 */
# define SEMICOLON		59
# define SPACE			32
# define CHAR			-1
# define PIPE			124
# define QUOTE			39
# define D_QUOTE		34
# define LEFT			60
# define RIGHT			62
# define DOLLAR			36
# define ESC_CHAR		92
#define GREATER			-2


typedef struct			s_info
{
	int					state;
	char				*input;
	int 				spec_case;
}						t_info;

typedef struct			s_token
{
	char				*value;
	int					type;
	struct s_token		*next;
}						t_token;

t_token		*lexer(char *input, int size);
void		print_lexer(t_token *lexer);
void		add_token(t_token **lst_token, char *data, int type);
t_info		tokenize_state_normal( char *input, t_token **lst_tok, int size, int spec_case);
t_info		tokenize_inside_dquote(char *input, t_token **lst_tok, int size);
t_info		tokenize_inside_squote(char *input, t_token **lst_tok, int size);
char		*skip_spaces(char *str);
char		next_char(char *str);
void		free_lst_tokens(t_token **lst);
#endif
