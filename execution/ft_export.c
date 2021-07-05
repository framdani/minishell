/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:39:05 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/05 10:12:20 by akhalidy         ###   ########.fr       */
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
		if (arg[i] == '=')
		{
			i++;
			while (arg[i] != '\0')
			{
				envv->value = ft_charjoin(envv->value, arg[i]);
				i++;
			}
		}
		else if (arg[i] == '\0')
		{
			free(envv->value);
			envv->value = NULL;
		}
	}
	return (envv);
}

void	ft_export_add(t_list **envl, char **args)
{
	t_list	*env;
	t_envv	*envv;
	int		i;

	i = 0;
	while (args[i])
	{
		envv = get_key_value(args[i]);
		if (!envv)
			return (ft_putendl_fd("not a valid identifier", 2));
		env = ft_find_node(*envl, envv->name);
		if (env)
		{
			if (envv->value)
			{
				free(env->value);
				env->value = envv->value;
			}
			free(envv->name);
		}
		else
		{
			if (!ft_strncmp(envv->name, "PWD", 4) && !g_help.on_pwd)
				g_help.on_pwd = 1;
			else if (!ft_strncmp(envv->name, "OLDPWD", 7) && !g_help.on_oldpwd)
				g_help.on_oldpwd = 1;
			ft_lstadd_back(envl, ft_lstnew(envv->name, envv->value));
		}
		free(envv);
		i++;
	}
}

void	ft_export(t_list **envl, char **args, int fd)
{
	t_list	*head;

	head = *envl;
	if (!*args)
	{
		ft_lstbubblesort(head);
		while (head)
		{
			ft_putstr_fd("declare -x ", fd);
			ft_putstr_fd(head->env, fd);
			if (head->value)
			{
				ft_putstr_fd("=\"", fd);
				ft_putstr_fd(head->value, fd);
				ft_putstr_fd("\"\n", fd);
			}
			else
				ft_putstr_fd("\n", fd);
			head = head->next;
		}
	}
	else
		ft_export_add(&head, args);
}
