/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:43:30 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/05 18:42:51 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_echo_check_flag(char **args, char *flag)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!ft_strncmp("-n", args[i], 2))
		{
			if ((args[i][2]) && ft_is_flag(args[i] + 2, 'n'))
				return (i);
			*flag = 'n';
		}
		else
			return (i);
		i++;
	}
	return (i);
}

void	ft_echo(char **args, int fd)
{
	int		i;
	char	flag;

	flag = 0;
	if (args)
	{
		i = ft_echo_check_flag(args, &flag);
		while (args[i])
		{
			ft_putstr_fd(args[i], fd);
			i++;
			if (args[i])
				ft_putchar_fd(' ', fd);
		}
	}
	if (flag != 'n')
		ft_putchar_fd('\n', fd);
	g_help.ret = 0;
}
