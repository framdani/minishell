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
	//int	len;
	t_list *tmp;

	tmp = *env;
	while (tmp !=	NULL)
	{
		if ((strcmp(name, "PWD") == 0 && g_help.on_pwd == 0)
				||(strcmp(name, "OLDPWD") == 0 && g_help.on_oldpwd == 0))
			return (NULL);
		if(strcmp(tmp->env, name) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	/*while (env && *env)
	{
		if (ft_strcmp(*env, name, len) == 0)
			return (*env + len);
		env++;
	}*/
	return (NULL);
}

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

char	*expander(t_token **lst_token, char *input, t_list **envl)
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
		if (token != NULL)
			expand_value(lst_token, token);
		else
			add_token(lst_token, "SPACE", SPACE);
	}
	free(new_value);
	return (input);
}

void 	expand_value_inside_dquote(t_token **lst_tok, char *value)
{
	char	*new_value;

	new_value = ft_strdup("");
	while (*value != '\0')
	{
		new_value = ft_charjoin(new_value, *value);
		value++;
	}
	add_token(lst_tok, new_value, CHAR);
	free(new_value);

}

char 	*expander_inside_dquote(t_token **lst_token, char *input, t_list **envl)
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
		token = get_env(new_value, envl);//search in envl
		if (token != NULL)
			expand_value_inside_dquote(lst_token, token);
		else
			add_token(lst_token, "SPACE", SPACE);
	}
	free(new_value);
	return (input);
}

char 	*expander_spec_case(t_token **lst_token, char *input, t_list **envl)
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
		if (token != NULL)
		{
			free(new_value);
			new_value = ft_strdup("");
			while (*token != '\0')
			{
				new_value = ft_charjoin(new_value, *token);
				token++;
			}
			add_token(lst_token, new_value, CHAR);
		}
		else
			add_token(lst_token, "SPACE", SPACE);
	}
	free(new_value);
	return (input);
}
