/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:47:40 by framdani          #+#    #+#             */
/*   Updated: 2021/07/10 16:56:36 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/parser.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <string.h>

char	*get_env(char *name, t_list **env)
{
	t_list	*tmp;

	tmp = *env;
	while (tmp != NULL)
	{	
		if (strcmp(tmp->env, name) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

void	tokenize_expanded_value(t_token **lst_tok, char *value)
{
	char	*new_value;

	new_value = ft_strdup("");
	while (*value != '\0' && *value == 32)
		value++;
	while (*value != '\0')
	{
		while (*value != 32 && *value != '\0')
		{
			new_value = ft_charjoin(new_value, *value);
			value++;
		}
		add_token(lst_tok, new_value, CHAR);
		free(new_value);
		new_value = ft_strdup("");
		if (*value == 32)
		{
			while (*value == 32 && *value != '\0')
				value++;
			add_token(lst_tok, "SPACE", SPACE);
		}
	}
	free(new_value);
}

void	add_expanded_value(t_token **lst_tok, char *token, int state,
	t_list **envl)
{
	char	*val;

	token = get_env(token, envl);
	if (token != NULL)
	{
		if (state == NORMAL)
			tokenize_expanded_value(lst_tok, token);
		else
			add_token(lst_tok, token, CHAR);
	}
	else
	{
		if (state == IN_DQUOTE)
		{
			val = ft_strdup("");
			add_token(lst_tok, val, CHAR);
			free(val);
		}
		else
			add_token(lst_tok, "SPACE", SPACE);
	}
}

void	expand_exit_status(t_token **lst_tok)
{
	char	*new_value;

	new_value = ft_itoa(g_help.ret);
	add_token(lst_tok, new_value, CHAR);
	free(new_value);
}

char	*expander(t_token **lst_token, char *input, t_list **envl, int state)
{
	char	*new_value;

	if (*input == '?')
	{
		expand_exit_status(lst_token);
		input++;
		return (input);
	}
	if (ft_isdigit(*input))
	{
		input++;
		add_token(lst_token, "SPACE", SPACE);
	}
	else if (ft_isalpha(*input) || *input == '_')
	{
		new_value = ft_strdup("");
		while (ft_isalnum(*input) || *input == '_')
		{
			new_value = ft_charjoin(new_value, *input);
			input++;
		}
		add_expanded_value(lst_token, new_value, state, envl);
		free(new_value);
	}
	return (input);
}
