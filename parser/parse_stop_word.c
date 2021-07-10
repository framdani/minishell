/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stop_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <framdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 15:16:55 by framdani          #+#    #+#             */
/*   Updated: 2021/07/10 18:09:34 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/parser.h"

int	is_delimiter(char c)
{
	if (c == '\'' || c == '\"' || c == LEFT || c == RIGHT
		|| c == SPACE || c == PIPE || c == '\0')
		return (1);
	return (0);
}

int	detect_state(t_token **lst_tok, char c, int state)
{
	char	*data;

	data = malloc(2);
	if (c == '\'')
	{
		if (state == NORMAL)
			state = IN_QUOTE;
		else
			state = NORMAL;
	}
	else if (c == '\"')
	{
		if (state == NORMAL)
			state = IN_DQUOTE;
		else
			state = NORMAL;
	}
	data[0] = c;
	data[1] = '\0';
	add_token(lst_tok, data, CHAR);
	free(data);
	return (state);
}

char	*join_no_special_chars(t_token **lst_tok, char *input)
{
	int		j;
	char	*data;

	j = 0;
	data = malloc(ft_strlen(input) + 1);
	while (!is_delimiter(*input))
	{
		data[j] = *input;
		j++;
		input++;
	}
	data[j] = '\0';
	add_token(lst_tok, data, CHAR);
	free(data);
	return (input);
}

char	*join_special_chars_inside_qt(t_token **lst_tok, char *input)
{
	char	*data;

	data = malloc(2);
	data[0] = *input;
	data[1] = '\0';
	add_token(lst_tok, data, CHAR);
	input++;
	free(data);
	return (input);
}

char	*parse_stop_word(t_token **lst_tok, char *input)
{
	int		state;

	state = NORMAL;
	while (*input != '\0')
	{
		input = join_no_special_chars(lst_tok, input);
		if (*input == '\"' || *input == '\'')
		{
			state = detect_state(lst_tok, *input, state);
			input++;
		}
		if (state == NORMAL)
			return (input);
		else
			input = join_special_chars_inside_qt(lst_tok, input);
	}
	if (state == IN_QUOTE || state == IN_DQUOTE)
		print_error_and_exit(lst_tok, 0);
	return (input);
}
