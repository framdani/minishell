/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:47:40 by framdani          #+#    #+#             */
/*   Updated: 2021/07/02 17:22:57 by akhalidy         ###   ########.fr       */
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
	if ((strcmp(name, "PWD") == 0 && g_help.on_pwd == 0)
		|| (strcmp(name, "OLDPWD") == 0 && g_help.on_oldpwd == 0))
		return (NULL);
	while (tmp != NULL)
	{
		
		if (strcmp(tmp->env, name) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}
// in case of command inside expanded value
void 	expand_value(t_token **lst_tok, char *value)
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

void	add_expanded_value(t_token **lst_tok, char *token, int state)
{
	char *val;

	if (token != NULL)
		if (state == NORMAL) //|| state == SPEC_CASE)
			expand_value(lst_tok, token);
		else
			add_token(lst_tok, token, CHAR);
	else
	{
		if (state == IN_DQUOTE)
		{
			//free(val);
			val = ft_strdup("");
			add_token(lst_tok, val, CHAR);
			free(val);
		}
		else
			add_token(lst_tok, "SPACE", SPACE);
	}
}

char	*expander(t_token **lst_token, char *input, t_list **envl, int state)
{
	char	*new_value;
	char	*token;

	new_value = ft_strdup("");
	
	if (*input == '?')
	{
		new_value = ft_charjoin(new_value, g_help.ret);
		add_token(lst_token, new_value, CHAR);
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
		//new_value = ft_strdup("");
		while (ft_isalnum(*input) || *input == '_')
		{
			new_value = ft_charjoin(new_value, *input);
			input++;
		}
		token = get_env(new_value, envl);
		//free(new_value);
		/*	if (token != NULL)
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
		add_expanded_value(lst_token, token, state);
	}
	free(new_value);
	return (input);
}
