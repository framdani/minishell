/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 12:13:32 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/01 17:30:09 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_cd_env_change_pwd(t_list *oldpwd, t_list *pwd)
{
	char	*tmp;

	if (oldpwd)
	{
		if (oldpwd->value)
			free(oldpwd->value);
		oldpwd->value = ft_strdup(pwd->value);
	}
	else
	{
		if (g_help.old_pwd)
			free(g_help.old_pwd);
		g_help.old_pwd = ft_strdup(pwd->value);
		g_help.on_oldpwd = 1;
	}
	if (pwd->value)
		free(pwd->value);
	tmp = getcwd(NULL, 0);
	if (tmp)
		pwd->value = tmp;
}	

void	ft_cd_env_change(t_list *oldpwd, char *pwd_old)
{
	if (g_help.on_pwd)
	{
		if (oldpwd)
		{
			free(oldpwd->value);
			oldpwd->value = ft_strdup(pwd_old);
		}
		else
		{
			free(g_help.old_pwd);
			g_help.old_pwd = ft_strdup("");
			g_help.on_oldpwd = 1;
		}
	}
	else
	{
		if (oldpwd)
		{
			free(oldpwd->value);
			oldpwd->value = ft_strdup("");
		}
		else
			g_help.on_oldpwd = 1;
		g_help.on_pwd = 1;
	}
}

int	ft_cd(t_list *envl, char **path)
{
	t_list	*oldpwd;
	t_list	*pwd;
	char	*pwd_old;
	char	*tmp;
	int		ret;

	if (!*path)
	{
		ret = ft_check_cd_void(&path, ft_find_node(envl, "HOME"));
		if (ret == -1)
			return (-1);
	}
	oldpwd = ft_find_node(envl, "OLDPWD");
	pwd = ft_find_node(envl, "PWD");
	pwd_old = getcwd(NULL, 0);
	if (!pwd_old && !ft_strncmp(*path, ".", 2))
	{
		ft_putendl_fd(strerror(errno), 2);
		return (0);
	}
	ft_check_cd_home(path, envl);
	if (chdir(*path) == -1 && ft_cd_print_error(*path))
	{
		free(pwd_old);
		return (-1);
	}
	if (ret == 5)
		ft_free(path);
	if (pwd)
		ft_cd_env_change_pwd(oldpwd, pwd);
	else
		ft_cd_env_change(oldpwd, pwd_old);
	if (pwd_old)
		free(pwd_old);
	return (1);
}
