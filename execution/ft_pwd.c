/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:53:34 by akhalidy          #+#    #+#             */
/*   Updated: 2021/06/29 16:53:44 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_pwd(t_list *envl)
{
	char	*path;
	t_list	*tmp;

	path = getcwd(NULL, 0);
	if (!path)
	{
		tmp = ft_find_node(envl, "PWD");
		if (tmp)
			path = tmp->value;
	}
	ft_putendl_fd(path, 1);
	if (path)
		free(path);
}
