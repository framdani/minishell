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

# define NORMAL 	= 1
# define IN_QUOTE 	= 2
# define IN_DQUOTE 	= 3

typedef struct 	s_token
{
	char 		*data;
	char 		type;
}				t_token;

typedef struct 	s_lexer
{
	t_token 	tok;
	t_token 	*next;
}				t_lexer;

#endif
