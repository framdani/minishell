/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 13:10:42 by framdani          #+#    #+#             */
/*   Updated: 2021/07/05 13:11:01 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"
#include "../includes/minishell.h"

int	is_valid_identifier(char *arg)
{
	int	i;

	i = 0;
	if (ft_isdigit(arg[0]) || arg[0] == '\0' || arg[0] == '=')
		return (0);
	return (1);
}

void	get_value(char *arg, int i, t_envv **envv)
{
	//char *value;

	//value = ft_strdup("");
	t_envv *tmp;

	tmp = *envv;
	i++;
	while (arg[i] != '\0')
	{
		tmp->value = ft_charjoin(tmp->value, arg[i]);
		i++;
	}
	//return (value);
}

t_envv	*get_key_value(char	*arg)
{
	t_envv		*envv;
	int			i;

	i = 0;
	envv = malloc(sizeof(t_envv));
	envv->name = ft_strdup("");
	envv->value = ft_strdup("");
	if (!is_valid_identifier(arg))
	{
		free(envv->name);
		free(envv->value);
		free(envv);
		return (NULL);
	}
	else
	{
		while (arg[i] != '=' && arg[i] != '\0')
		{
			if (arg[i] != '_' && !ft_isalnum(arg[i]))
			{
				free(envv->name);
				free(envv->value);
				free(envv);
				return (NULL);
			}
			envv->name = ft_charjoin(envv->name, arg[i]);
			i++;
		}
		if (arg[i] == '=')//get_value
		{
			//i++;
			/*while (arg[i] != '\0')
			{
				envv->value = ft_charjoin(envv->value, arg[i]);
				i++;
			}*/
			get_value(arg, i, &envv);
		}
		else if (arg[i] == '\0')
		{
			free(envv->value);
			envv->value = NULL;
		}
	}
	return (envv);
}
