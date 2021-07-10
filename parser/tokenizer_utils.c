/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <framdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:57:03 by framdani          #+#    #+#             */
/*   Updated: 2021/07/10 15:48:32 by framdani         ###   ########.fr       */
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

char	*tokenize_redirection(t_token **lst_tok, char *input)
{
	if (*input == '<')
	{
		input++;
		if (*input == '<')
		{
			add_token(lst_tok, "LESSER", LESSER);
			input++;
			input = parse_stop_word(lst_tok, input);
		}
		else
			add_token(lst_tok, "LEFT", LEFT);
	}
	else if (*input == '>')
	{
		input++;
		if (*input == '>')
		{
			add_token(lst_tok, "GREATER", GREATER);
			input++;
		}
		else
			add_token(lst_tok, "RIGHT", RIGHT);
	}
	input = skip_spaces(input);
	return (input);
}

t_info	tokenize_expander(t_token **lst_tok, char *input, t_list **envl,
	int spec_case)
{
	char	*data;
	t_info	info;

	info.spec_case = spec_case;
	input++;
	info.input = input;
	if (*info.input == SPACE || *info.input == '\0' || *info.input == DOLLAR)
	{
		data = ft_strdup("$");
		add_token(lst_tok, data, CHAR);
		free(data);
	}
	else if (info.spec_case == 1)
	{
		info.spec_case = 0;
		info.input = expander(lst_tok, info.input, envl, SPEC_CASE);
	}
	else
		info.input = expander(lst_tok, info.input, envl, NORMAL);
	info.state = NORMAL;
	return (info);
}

t_info	concatenate_chars(t_token **lst_tok, char *input, int spec_case)
{
	char	*data;
	t_info	info;
	int		j;
	int		size;

	j = 0;
	size = ft_strlen(input);
	data = malloc(size + 1);
	info.spec_case = spec_case;
	j = 0;
	while (*input != '\0' && no_special_char(*input))
	{
		if (*input == '=' && next_char(input) == '$')
			info.spec_case = 1;
		data[j] = *input;
		j++;
		input++;
	}
	data[j] = '\0';
	add_token(lst_tok, data, CHAR);
	free(data);
	info.input = input;
	info.state = NORMAL;
	return (info);
}

t_info	change_state(char *input, int spec_case)
{
	t_info	info;

	info.spec_case = spec_case;
	if (*input == QUOTE)
		info.state = IN_QUOTE;
	else
		info.state = IN_DQUOTE;
	input++;
	info.input = input;
	return (info);
}
