/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:03:46 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/05 18:31:04 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_valid_arg(char *arg)
{
	int	i;

	i = 0;
	if (ft_isdigit(arg[i]))
		return (0);
	while (arg[i])
	{
		if (!ft_isalnum(arg[i]) && arg[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	ft_unset(t_list **envl, char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (is_valid_arg(args[i]))
		{
			if (!ft_strncmp("PWD", args[i], 4))
				g_help.on_pwd = 0;
			else if (!ft_strncmp("OLDPWD", args[i], 7))
				g_help.on_oldpwd = 0;
			ft_delete_node(envl, args[i]);
		}
		else
		{
			ft_putstr_fd("minishell: unset: ", 2);
			ft_putstr_fd(args[i], 2);
			ft_putendl_fd(": not a valid identifier", 2);
			g_help.ret = 1;
		}
		i++;
	}
}
