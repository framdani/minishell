/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_hd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <framdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:47:07 by framdani          #+#    #+#             */
/*   Updated: 2021/07/10 15:43:40 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/parser.h"

char	*remove_quotes(char *str)
{
	char	*new_val;
	int		i;

	i = 0;
	new_val = ft_strdup("");
	while (str[i] != '\0')
	{
		if (str[i] != '\'' && str[i] != '\"')
			new_val = ft_charjoin(new_val, str[i]);
		i++;
	}
	return (new_val);
}

int	quote_exist(char *input)
{
	int	i;

	i = 0;
	while (input[i] != '\0' && input[i] != 32)
	{
		if (input[i] == '\'' || input[i] == '\"')
			return (1);
		i++;
	}
	return (0);
}

void	exit_status(char **ret)
{
	char	*exit_status;
	char	*pfree;

	exit_status = ft_itoa(g_help.ret);
	pfree = *ret;
	*ret = ft_strjoin(*ret, exit_status);
	free(exit_status);
	free(pfree);
}

int	expand_value_hd(char *input, int i, char **ret, t_list **envl)
{
	char	*to_expand;
	char	*new_value;
	char	*pfree;

	if (ft_isdigit(input[i]))
		i++;
	else if (ft_isalpha(input[i]) || input[i] == '_')
	{
		to_expand = ft_strdup("");
		while (ft_isalnum(input[i]) || input[i] == '_')
		{
			to_expand = ft_charjoin(to_expand, input[i]);
			i++;
		}
		new_value = get_env(to_expand, envl);
		free(to_expand);
		if (new_value != NULL)
		{
			pfree = *ret;
			*ret = ft_strjoin(*ret, new_value);
			free(pfree);
		}
	}
	return (i);
}

char	*parse_line_hd(char *input, t_list **envl)
{
	int		i;
	char	*ret;

	i = 0;
	ret = ft_strdup("");
	while (input[i] != '\0')
	{
		if (input[i] == '$')
		{
			i++;
			if (input[i] == '?')
			{
				i++;
				exit_status(&ret);
			}
			i = expand_value_hd(input, i, &ret, envl);
		}
		else
		{
			ret = ft_charjoin(ret, input[i]);
			i++;
		}
	}
	free(input);
	return (ret);
}
