/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:53:34 by akhalidy          #+#    #+#             */
/*   Updated: 2021/06/26 15:56:31 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//mkdir tst; cd tst; rm -rf ../tst; pwd : with PWD unseted ;)
// you sould store the value of PWD in a global var
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
		// else normaly i should use the global var. ( :'-( )!
	}
	ft_putendl_fd(path, 1);
	if (path)
		free(path);
}