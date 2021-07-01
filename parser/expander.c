/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:47:40 by framdani          #+#    #+#             */
/*   Updated: 2021/05/26 15:47:43 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"
#include "../includes/parser.h"
#include "../libft/libft.h"
#include <string.h>

char	*get_env(char *name, t_list **env)
{
	t_list	*tmp;

	tmp = *env;
	while (tmp != NULL)
	{
		if ((strcmp(name, "PWD") == 0 && g_help.on_pwd == 0)
			|| (strcmp(name, "OLDPWD") == 0 && g_help.on_oldpwd == 0))
			return (NULL);
		if (strcmp(tmp->env, name) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

void	add_expnaded_value(t_token **lst_tok, char *token, int state, char *val)
{
	if (token != NULL)
		add_token(lst_tok, token, CHAR);
	else
	{
		if (state == IN_DQUOTE)
		{
			free(val);
			val = ft_strdup("");
			add_token(lst_tok, val, CHAR);
		}
		else
			add_token(lst_tok, "SPACE", SPACE);
	}
	free(val);
}

char	*expander(t_token **lst_token, char *input, t_list **envl, int state)
{
	char	*new_value;
	char	*token;

	new_value = ft_strdup("");
	if (*input == '?')
	{
		add_token(lst_token, "$?", CHAR);
		input++;
		free(new_value);
		return (input);
	}
	if (ft_isdigit(*input))
	{
		input++;
		add_token(lst_token, "SPACE", SPACE);
	}
	else if (ft_isalpha(*input) || *input == '_')
	{
		while (ft_isalnum(*input) || *input == '_')
		{
			new_value = ft_charjoin(new_value, *input);
			input++;
		}
		token = get_env(new_value, envl);
		/*if (token != NULL)
			add_token(lst_token, token, CHAR);
		else
		{
			if (state == IN_DQUOTE)
			{
				free(new_value);
				new_value = ft_strdup("");
				add_token(lst_token, new_value, CHAR);
			}
			else
				add_token(lst_token, "SPACE", SPACE);
		}*/
		add_expnaded_value(lst_token, token, state, new_value);
	}
//	free(new_value);
	return (input);
}
