/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <framdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:20:32 by framdani          #+#    #+#             */
/*   Updated: 2021/07/05 17:57:13 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# define NORMAL 1
# define IN_QUOTE 2
# define IN_DQUOTE 3
# define SPEC_CASE 4
# include "../libft/libft.h"
# define SPACE			32
# define CHAR			-1
# define PIPE			124
# define QUOTE			39
# define D_QUOTE		34
# define LEFT			60
# define RIGHT			62
# define DOLLAR			36
# define GREATER		-2
# define LESSER			-3

typedef struct s_info
{
	int		state;
	char	*input;
	int		spec_case;
}						t_info;

typedef struct s_token
{
	char				*value;
	int					type;
	struct s_token		*next;
}						t_token;

t_token	*lexer(char *input, int size, t_list **envl);
void	print_lexer(t_token *lexer);
void	add_token(t_token **lst_token, char *data, int type);
t_info	tokenize_state_normal( char *input, t_token **lst_tok, int spec_case,
			t_list **envl);
t_info	tokenize_inside_dquote(char *input, t_token **lst_tok, int size,
			t_list **envl);
t_info	tokenize_inside_squote(char *input, t_token **lst_tok, int size);
char	*skip_spaces(char *str);
char	next_char(char *str);
void	free_lst_tokens(t_token **lst);
t_info	tokenize_expander(t_token **lst_tok, char *input, t_list **envl,
			int spec_case);
char	*tokenize_redirection(t_token **lst_tok, char *input);
t_info	concatenate_chars(t_token **lst_tok, char *input, int spec_case);
t_info	change_state(char *input, int spec_case);
#endif
