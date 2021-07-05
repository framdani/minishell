/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:03:46 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/05 13:15:43 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_unset(t_list **envl, char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!ft_strncmp("PWD", args[i], 4))
			g_help.on_pwd = 0;
		else if (!ft_strncmp("OLDPWD", args[i], 7))
			g_help.on_oldpwd = 0;
		ft_delete_node(envl, args[i]);
		i++;
	}
}
