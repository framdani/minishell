/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:37:34 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/10 17:12:07 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_isinteger(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void	ft_exit(char **args, int fork)
{
	if (!*args)
	{
		if (fork)
			ft_putendl_fd("exit", 1);
		exit(g_help.ret);
	}
	if (!ft_isinteger(*args))
	{
		if (!(args[1]))
		{
			if (fork)
				ft_putendl_fd("exit", 1);
			exit((unsigned char)ft_atoi(*args));
		}
		ft_putendl_fd("exit", 2);
		ft_putendl_fd("minishell: exit: too many arguments", 2);
		g_help.ret = 1;
	}
	else
	{
		ft_putstr_fd("minishell$ exit: ", 2);
		ft_putstr_fd(*args, 2);
		ft_putendl_fd(": numeric argument required", 2);
		exit(255);
	}
}
