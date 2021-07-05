/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:53:34 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/05 18:59:48 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_pwd(t_list *envl)
{
	char	*path;
	t_list	*tmp;
	int		k;

	k = 0;
	path = getcwd(NULL, 0);
	if (!path)
	{
		tmp = ft_find_node(envl, "PWD");
		if (tmp)
		{
			k = 1;
			path = tmp->value;
		}
	}
	ft_putendl_fd(path, 1);
	if (path && !k)
		free(path);
	g_help.ret = 0;
}
