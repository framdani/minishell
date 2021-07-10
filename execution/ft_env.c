/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:23:17 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/10 17:05:12 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_lst_print_fd(t_list	*head, int fd)
{
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
		if (head->value)
		{
			ft_putstr_fd(head->env, fd);
			ft_putstr_fd("=", fd);
			ft_putstr_fd(head->value, fd);
			ft_putstr_fd("\n", fd);
		}
		head = head->next;
	}
}

void	ft_env(t_list *envl, char **args, int fd)
{
	g_help.ret = 0;
	if (*args)
	{
		ft_putstr_fd("env: ", 2);
		ft_putstr_fd(*args, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		g_help.ret = 127;
	}
	else
		ft_lst_print_fd(envl, fd);
}
