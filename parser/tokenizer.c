/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <framdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 12:38:31 by framdani          #+#    #+#             */
/*   Updated: 2021/07/05 16:28:40 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"
#include "../libft/libft.h"

char	*tokenize_redirection(t_token **lst_tok, char *input)
{
	if (*input == '<')
	{
		input++;
		if (*input == '<')
		{
			add_token(lst_tok, "LESSER", LESSER);
			input++;
		}
		else
			add_token(lst_tok, "LEFT", LEFT);
		input = skip_spaces(input);
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
		input = skip_spaces(input);
	}
	return (input);
}

t_info tokenize_expander(t_token **lst_tok, char *input, t_list **envl, int spec_case)
{
	char *data;
	t_info info;

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

t_info concatenate_chars(t_token **lst_tok,char *input, int spec_case)
{
	char *data;
	t_info info;
	int j;
	int size;

	j =0;
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
	return(info);
}

t_info change_state(char *input, int spec_case)
{
	t_info info;

	info.spec_case = spec_case;
	if (*input == QUOTE)
		info.state = IN_QUOTE;
	else
		info.state = IN_DQUOTE;
	input++;
	info.input = input;
	return(info);
}

t_info	tokenize_state_normal(char *input, t_token **lst_tok, int spec_case, t_list **envl)
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

t_info		tokenize_inside_dquote(char *input, t_token **lst_tok, int size, t_list **envl)
{
	char *data;
	int j;
	t_info	info;
	info.state= IN_DQUOTE;
	info.input = input;
	if (*info.input == DOLLAR)
	{
		info.input++;
		if (*info.input == SPACE || *info.input == '\0' || *info.input == '\"' || *info.input == '$')
		{
			data = ft_strdup("$");
			add_token(lst_tok, data, CHAR);
			free(data);
		}
		else
			info.input = expander(lst_tok, info.input, envl, IN_DQUOTE);
	}
	else if (info.state == IN_DQUOTE && *info.input != '\0')
	{
		data = malloc(size + 1);
		j = 0;
		while (*info.input != D_QUOTE && *info.input != DOLLAR && *info.input != '\0')
		{
			data[j] = *info.input;
			j++;
			info.input++;
		}
		data[j] = '\0';
		add_token(lst_tok, data, CHAR);
		free(data);
	}
	if (*info.input != '\0' && *info.input == D_QUOTE)
	{
		//input++;
		info.state = NORMAL;
		info.input++;
		return (info);
	}
	//info.input = input;
	return (info);
}

t_info 	tokenize_inside_squote(char *input, t_token **lst_tok, int size)
{
	char *data;
	int j;
	data = malloc(size);
	j = 0;
	t_info	info;
	info.state = IN_QUOTE;
	info.input = input;
	while (*input != QUOTE && *input != '\0')
	{
		data[j++] = *input;
		input++;
	}
	data[j] = '\0';
	add_token(lst_tok, data, CHAR);
	free(data);
	if (*input == QUOTE)
	{
		input++;
		info.input = input;
		info.state = NORMAL;
		return (info);
	}
	info.input = input;
	info.state = IN_QUOTE;
	return (info);
}
