/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 12:38:31 by framdani          #+#    #+#             */
/*   Updated: 2021/06/27 12:38:34 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"
#include "../libft/libft.h"

t_info		tokenize_state_normal(char *input, t_token **lst_tok, int size, int spec_case, t_list **envl)
{
	char *data;
	int j;
	//char c;
	t_info	info;

	info.input = input;
	info.state = NORMAL;
	info.spec_case = spec_case;
	if (*input == ' ' || *input == '\t')
	{
		input = skip_spaces(input);
		add_token(lst_tok, "SPACE", SPACE);
	}
	/*else if (*input == ESC_CHAR)
	{
		//check next char => if char skip don't store it
		c = next_char(input);
		if  (!c)
			add_token(lst_tok, "ESCAPE", ESC_CHAR);
		else if (ft_strchr("<>|;$\"\'\\ ", c))
		{
			data = malloc(2);
			data[0]=c;
			data[1] = '\0';
			add_token(lst_tok, data, CHAR);
			data = NULL;
			free(data);
			input++;
		}
		input++;
	}*/
	/*else if (*input == ';')
	{
		input++;
		add_token(lst_tok, "SEMICOLON", SEMICOLON);
		input = skip_spaces(input);
	}*/
	else if (*input == '|')
	{
		input++;
		add_token(lst_tok, "PIPE", PIPE);
		input = skip_spaces(input);
	}
	else if (*input == '<')
	{
		input++;
		/*add_token(lst_tok, "LEFT", LEFT);
		if (*input == ' ')
		{
			input = skip_spaces(input);
			if (*input == '>')
				add_token(lst_tok, "SPACE", SPACE);
		}*/
		if (*input == '<')
		{
			add_token(lst_tok, "LESSER", LESSER);
			input++;
		}
		else
		{
			add_token(lst_tok, "LEFT", LEFT);
		}
		input = skip_spaces(input);
	}
	else if (*input == '>')
	{
		input++;
		//input = skip_spaces(input);
		if (*input == '>')
		{
			add_token(lst_tok, "GREATER", GREATER);
			input++;
		}
		else
		{
			add_token(lst_tok, "RIGHT", RIGHT);
		}
		input = skip_spaces(input);
	}
	else if (*input == '$')
	{
		input++;
		if (*input == SPACE || *input == '\0' || *input == DOLLAR)
		{
			data = malloc(2);
			data[0] = '$';
			data[1] = '\0';
			add_token(lst_tok, data, CHAR);
			free(data);
		}
		else if (info.spec_case == 1)
		{
			info.spec_case = 0;
			input = expander_spec_case(lst_tok, input, envl);
		}
		else
			input = expander(lst_tok, input, envl);
	}
	else if (*input == QUOTE)
	{
		//state = IN_QUOTE;
		input++;
		info.input = input;
		info.state = IN_QUOTE;
		return (info);
	}
	else if (*input == D_QUOTE)
	{
		///state = IN_DQUOTE;
		input++;
		info.input = input;
		info.state = IN_DQUOTE;
		return (info);
	}
	else
	{
		data = malloc(size);
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
	}
	info.input = input;
	return (info);
}

t_info		tokenize_inside_dquote(char *input, t_token **lst_tok, int size, t_list **envl)
{
	char *data;
	//char c;
	int j;
	t_info	info;
	info.state= IN_DQUOTE;
	info.input = input;
	if (*input == DOLLAR)
	{
		input++;
		if (*input == SPACE || *input == '\0')
			add_token(lst_tok, "DOLLAR", DOLLAR);
		else
			input = expander_inside_dquote(lst_tok, input, envl);
			//input = expander(lst_tok, input);
	}
	/*else if (*input == ESC_CHAR)
	{
		c = next_char(input);
		if (!c)
			add_token(lst_tok, "ESCAPE", ESC_CHAR);
		else if (ft_strchr("$\"\\", c))
		{
			data = malloc(2);
			data[0] = c;
			data[1] = '\0';
			add_token(lst_tok, data, CHAR);
			data = NULL;
			free(data);
			input++;
		}
		else
		{
			data = malloc(2);
			data[0] = '\\';
			data[1] = '\0';
			add_token(lst_tok, data, CHAR);
			free(data);
		}
		input++;
	}*/
	else if (info.state == IN_DQUOTE && *input != '\0')
	{
		data = malloc(size);
		j = 0;
		while (*input != D_QUOTE && *input != DOLLAR && *input != '\0')
		{
			data[j] = *input;
			j++;
			input++;
		}
		data[j] = '\0';
		add_token(lst_tok, data, CHAR);
		free(data);
	}
	if (*input != '\0' && *input == D_QUOTE)
	{
		//state = NORMAL;
		input++;
		info.state = NORMAL;
		info.input = input;
		return (info);
	}
	info.input = input;
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
		data[j] = *input;
		j++;
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
