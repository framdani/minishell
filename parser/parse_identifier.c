/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <framdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 13:10:42 by framdani          #+#    #+#             */
/*   Updated: 2021/07/05 15:49:32 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_valid_identifier(char *arg)
{
	int	i;

	i = 0;
	if (ft_isdigit(arg[0]) || arg[0] == '\0' || arg[0] == '=')
		return (0);
	return (1);
}

void	get_value(char *arg, t_envv **envv)
{
	t_envv	*tmp;

	tmp = *envv;
	arg++;
	while (*arg != '\0')
	{
		tmp->value = ft_charjoin(tmp->value, *arg);
		arg++;
	}
}

t_envv	*free_envv(t_envv **envv)
{
	t_envv	*tmp;

	tmp = *envv;
	free(tmp->name);
	free(tmp->value);
	free(tmp);
	return (NULL);
}

t_envv	*get_key_value(char	*arg)
{
	t_envv		*envv;

	envv = malloc(sizeof(t_envv));
	envv->name = ft_strdup("");
	envv->value = ft_strdup("");
	if (!is_valid_identifier(arg))
		return (free_envv(&envv));
	else
	{
		while (*arg != '=' && *arg != '\0')
		{
			if (*arg != '_' && !ft_isalnum(*arg))
				return (free_envv(&envv));
			envv->name = ft_charjoin(envv->name, *arg);
			arg++;
		}
		if (*arg == '=')
			get_value(arg, &envv);
		else if (*arg == '\0')
		{
			free(envv->value);
			envv->value = NULL;
		}
	}
	return (envv);
}
