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
# define SEMICOLON	 59
# define SPACE		 32
# define CHAR		 -1
# define PIPE		 124
# define QUOTE		 39
# define D_QUOTE	 34
# define LEFT		 60
# define RIGHT		62
# define DOLLAR 36



typedef struct			s_token
{
	char				*value;
	int					type;
	struct s_token		*next;
}						t_token;

t_token		*build_lexer(char *input);
void		print_lexer(t_token *lexer);
#endif
