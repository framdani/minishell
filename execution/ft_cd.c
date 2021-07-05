/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 12:13:32 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/05 13:23:51 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_cd_env_change(t_list *oldpwd, t_list *pwd, t_list **envl)
{
	char	*tmp;

	if (oldpwd)
	{
		if (oldpwd->value)
			free(oldpwd->value);
		oldpwd->value = ft_strdup(pwd->value);
	}
	else
		ft_lstadd_back(envl, ft_lstnew(ft_strdup("OLDPWD"),
				ft_strdup(pwd->value)));
	if (pwd->value)
		free(pwd->value);
	tmp = getcwd(NULL, 0);
	if (tmp)
		pwd->value = tmp;
}	

void	ft_cd_env_reset(t_list *oldpwd, char *pwd_old, t_list **envl)
{
	ft_lstadd_back(envl, ft_lstnew(ft_strdup("PWD"), getcwd(NULL, 0)));
	if (oldpwd)
	{
		free(oldpwd->value);
		oldpwd->value = ft_strdup(" ");
	}
	else
		ft_lstadd_back(envl, ft_lstnew(ft_strdup("OLDPWD"), ft_strdup(" ")));
}

int	ft_cd_initialize(t_cd_hlp *var, t_list **envl, char ***path)
{
	if (!**path)
	{
		var->ret = ft_check_cd_void(path, ft_find_node(*envl, "HOME"));
		if (var->ret == -1)
			return (-1);
	}
	var->oldpwd = ft_find_node(*envl, "OLDPWD");
	var->pwd = ft_find_node(*envl, "PWD");
	var->pwd_old = getcwd(NULL, 0);
	return (1);
}

int	ft_cd(t_list **envl, char **path)
{
	t_cd_hlp	var;

	if (ft_cd_initialize(&var, envl, &path) == -1)
		return (1);
	if (!var.pwd_old && !ft_strncmp(*path, ".", 2))
	{
		ft_putendl_fd(strerror(errno), 2);
		return (1);
	}
	ft_check_cd_home(path, *envl);
	if (chdir(*path) == -1 && ft_cd_print_error(&path, var.ret))
	{
		free(var.pwd_old);
		return (1);
	}
	if (var.pwd)
		ft_cd_env_change(var.oldpwd, var.pwd, envl);
	else
		ft_cd_env_reset(var.oldpwd, var.pwd_old, envl);
	if (var.ret == 5)
		ft_free(path);
	free(var.pwd_old);
	return (0);
}
