/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_outils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <framdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:23:02 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/05 15:23:27 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_cd_print_error(char *path)
{
	ft_putstr_fd("bash: cd: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

void	ft_check_cd_home(char **path, t_list *envl)
{
	t_list	*lst;
	char	*home;
	char	*pfree;

	pfree = NULL;
	lst = ft_find_node(envl, "HOME");
	if (!lst)
		home = getenv("HOME");
	else if (lst)
		home = ft_strdup(lst->value);
	if (*path && **path == '~')
	{
		pfree = *path;
		*path = ft_strjoin(home, *path + 1);
		free(pfree);
	}
}

int	ft_check_cd_void(char ***path, t_list *home)
{
	if (!home && !**path)
	{
		ft_putstr_fd("bash: cd: HOME not set\n", 2);
		return (-1);
	}
	else if (home && !**path)
	{
		*path = ft_split("~", ' ');
		return (5);
	}
	return (0);
}
