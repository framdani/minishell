/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:39:05 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/05 21:54:53 by akhalidy         ###   ########.fr       */
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

void	ft_export_print_error(char *arg)
{
	not_valid_id(arg);
	g_help.ret = 1;
}

void	ft_export_add(t_list **envl, char **args)
{
	t_list	*env;
	t_envv	*envv;
	int		i;

	i = -1;
	while (args[++i])
	{
		envv = get_key_value(args[i]);
		if (!envv)
		{
			ft_export_print_error(args[i]);
			continue ;
		}
		env = ft_find_node(*envl, envv->name);
		if (env)
			ft_free_envv(&env, &envv);
		else
			ft_set_global_pwd_oldpwd(envv, envl);
		free(envv);
	}
}

void	ft_print_export(t_list *head, int fd)
{
	ft_lstbubblesort(head);
	while (head)
	{
		if (!ft_strncmp(head->env, "PWD", 4) && !g_help.on_pwd)
		{
			head = head->next;
			continue ;
		}
		else if (!ft_strncmp(head->env, "OLDPWD", 7) && !g_help.on_oldpwd)
		{
			head = head->next;
			continue ;
		}
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

void	ft_export(t_list **envl, char **args, int fd)
{
	t_list	*head;

	head = *envl;
	g_help.ret = 0;
	if (!*args)
		ft_print_export(head, fd);
	else
		ft_export_add(&head, args);
}
