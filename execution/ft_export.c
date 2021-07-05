/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:39:05 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/05 18:41:52 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_set_global_pwd_oldpwd(t_envv *envv, t_list **envl)
{
	if (!ft_strncmp(envv->name, "PWD", 4) && !g_help.on_pwd)
		g_help.on_pwd = 1;
	else if (!ft_strncmp(envv->name, "OLDPWD", 7) && !g_help.on_oldpwd)
		g_help.on_oldpwd = 1;
	ft_lstadd_back(envl, ft_lstnew(envv->name, envv->value));
}

void	ft_export_print_error(void)
{
	ft_putendl_fd("not a valid identifier", 2);
	g_help.ret = 1;
}

void	ft_export_add(t_list **envl, char **args)
{
	t_list	*env;
	t_envv	*envv;
	int		i;

	i = -1;
	g_help.ret = 0;
	while (args[++i])
	{
		envv = get_key_value(args[i]);
		if (!envv)
			return (ft_export_print_error());
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
			ft_set_global_pwd_oldpwd(envv, envl);
		free(envv);
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
