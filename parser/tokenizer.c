/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <framdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 12:38:31 by framdani          #+#    #+#             */
/*   Updated: 2021/07/05 17:42:29 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"
#include "../libft/libft.h"

t_info	tokenize_state_normal(char *input, t_token **lst_tok, int spec_case,
	t_list **envl)
{
	t_info	info;

	info.input = input;
	info.state = NORMAL;
	info.spec_case = spec_case;
	if (*info.input == ' ' || *info.input == '\t')
	{
		info.input = skip_spaces(info.input);
		add_token(lst_tok, "SPACE", SPACE);
	}
	else if (*info.input == '|')
	{
		info.input++;
		add_token(lst_tok, "PIPE", PIPE);
		info.input = skip_spaces(info.input);
	}
	else if (*info.input == '<' || *info.input == '>')
		info.input = tokenize_redirection(lst_tok, info.input);
	else if (*info.input == '$')
		info = tokenize_expander(lst_tok, info.input, envl, info.spec_case);
	else if (*info.input == QUOTE || *info.input == D_QUOTE)
		return (change_state(info.input, info.spec_case));
	else
		return (concatenate_chars(lst_tok, info.input, info.spec_case));
	return (info);
}

t_info	concat_chars_dqoutes(t_token **lst_tok, char *input, int size)
{
	char	*data;
	t_info	info;
	int		j;

	info.input = input;
	info.state = IN_DQUOTE;
	data = malloc(size + 1);
	j = 0;
	while (*info.input != D_QUOTE && *info.input != DOLLAR
		&& *info.input != '\0')
	{
		data[j] = *info.input;
		j++;
		info.input++;
	}
	data[j] = '\0';
	add_token(lst_tok, data, CHAR);
	free(data);
	return (info);
}

t_info	tokenize_expander_dqoutes(t_token **lst_tok, char *input, t_list **envl)
{
	t_info	info;
	char	*data;

	info.state = IN_DQUOTE;
	info.input = input;
	info.input++;
	if (*info.input == SPACE || *info.input == '\0' || *info.input == '\"'
		|| *info.input == '$')
	{
		data = ft_strdup("$");
		add_token(lst_tok, data, CHAR);
		free(data);
	}
	else
		info.input = expander(lst_tok, info.input, envl, IN_DQUOTE);
	return (info);
}

t_info	tokenize_inside_dquote(char *input, t_token **lst_tok, int size,
	t_list **envl)
{
	t_info	info;

	info.state = IN_DQUOTE;
	info.input = input;
	if (*info.input == DOLLAR)
		info = tokenize_expander_dqoutes(lst_tok, info.input, envl);
	else if (info.state == IN_DQUOTE && *info.input != '\0')
		info = concat_chars_dqoutes(lst_tok, info.input, size);
	if (*info.input != '\0' && *info.input == D_QUOTE)
	{
		info.state = NORMAL;
		info.input++;
		return (info);
	}
	return (info);
}

t_info	tokenize_inside_squote(char *input, t_token **lst_tok, int size)
{
	char	*data;
	int		j;
	t_info	info;

	data = malloc(size + 1);
	j = 0;
	info.state = IN_QUOTE;
	info.input = input;
	while (*info.input != QUOTE && *info.input != '\0')
	{
		data[j] = *info.input;
		j++;
		info.input++;
	}
	data[j] = '\0';
	add_token(lst_tok, data, CHAR);
	free(data);
	if (*info.input == QUOTE)
	{
		info.input++;
		info.state = NORMAL;
		return (info);
	}
	info.state = IN_QUOTE;
	return (info);
}
