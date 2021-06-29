/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:17:56 by framdani          #+#    #+#             */
/*   Updated: 2021/06/02 10:42:40 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"
#include "../libft/libft.h"

void	add_token(t_token **lst_tok, char *data, int type)
{
	t_token		*new;
	t_token		*tmp;

	new = malloc(sizeof(t_token));
	if (new != NULL)
	{
		new->next = NULL;
		new->value = ft_strdup(data);
		new->type = type;
		if (*lst_tok == NULL)
			*lst_tok = new;
		else
		{
			tmp = *lst_tok;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
}

char	*skip_spaces(char *str)
{
	while (*str != '\0' && (*str == 32 || *str == '\t'))
		str++;
	return (str);
}

char	next_char(char *str)
{
	str++;
	return (*str);
}

t_token	*check_return_value(int state, t_token **lst_tok)
{
	if (state == IN_QUOTE || state == IN_DQUOTE)
	{
		print_error_and_exit(lst_tok, 0);
		return (NULL);
	}
	else
		return (*lst_tok);
}

t_token	*lexer(char *input, int size, t_list **envl)
{
	t_token		*lst_tok;
	t_info		info;

	lst_tok = NULL;
	input = skip_spaces(input);
	info.state = NORMAL;
	info.spec_case = 0;
	while (*input != '\0')
	{
		while (info.state == NORMAL && *input != '\0')
		{
			info = tokenize_state_normal(input, &lst_tok, size, info.spec_case, envl);
			input = info.input;
		}
		while (info.state == IN_QUOTE && *input != '\0')
		{
			info = tokenize_inside_squote(input, &lst_tok, size);
			input = info.input;
		}
		while (info.state == IN_DQUOTE && *input != '\0')
		{
			info = tokenize_inside_dquote(input, &lst_tok, size, envl);
			input = info.input;
		}
	}
	return (check_return_value(info.state, &lst_tok));
}
