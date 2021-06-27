/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 12:13:32 by akhalidy          #+#    #+#             */
/*   Updated: 2021/06/27 19:49:02 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
	}
	if (pfree)
		free(pfree);
	if (home)
		free(home);
}

int		ft_check_cd_void(char ***path, t_list *home)
{
	if (!home && !**path)
	{
		ft_putstr_fd("bash: cd: HOME not set\n", 2);
		return(-1);	
	}
	else if (home && !**path)
	{
		*path = ft_split("~", ' ');
		return (5);
	}
	return(0);
}

void	set_pwd_oldpwd(t_list *envl, char *pwd_old)
{
	t_list	*oldpwd;
	t_list	*pwd;
	// char	*pfree;
	
	oldpwd = ft_find_node(envl, "OLDPWD");
	pwd = ft_find_node(envl, "PWD");
	if (pwd)
	{
		if (oldpwd)
		{
			if (oldpwd->value)
				free(oldpwd->value);
			oldpwd->value = ft_strdup(pwd->value);
		}
		else
			ft_lstadd_back(&envl, ft_lstnew("OLDPWD", pwd_old));
		if (pwd->value)
			free(pwd->value);
		pwd->value = getcwd(NULL, 0);
	}
	else
	{
		ft_lstadd_back(&envl, ft_lstnew("PWD", pwd_old));
		// pfree = oldpwd->value;
		if (oldpwd->value)
			free(oldpwd->value);
		oldpwd->value = ft_strdup(" ");
	}
}

int	ft_check_cd_back(char **path, t_list *oldpwd)
{
	if (**path == '-' && !*(*path + 1))
	{
		if (oldpwd)// && *oldpwd->value)
		{
			free(*path);
			if (*oldpwd->value)
			*path = ft_strdup(oldpwd->value);
		}
		else if (!oldpwd && g_help.on_oldpwd)
		{
			if (g_help.old_pwd)
			{
				if (*g_help.old_pwd)
					*path = g_help.old_pwd;
			}
			else
			{
				ft_putstr_fd("bash: cd: OLDPWD not set\n", 2);
				return(-1);	
			}
		}
	}
	return(0);
}

// Here is the cutest one if you by any chance need it!a

// int	ft_check_cd_back(char **path, t_list *oldpwd)
// {
// 	if (**path == '-' && !*(*path + 1))
// 	{
// 		if (oldpwd && *oldpwd->value)
// 			*path = oldpwd->value;
// 		else if (!oldpwd && g_help.on_oldpwd && g_help.old_pwd && *g_help.old_pwd)
// 			*path = g_help.old_pwd;
// 		else
// 		{
// 			ft_putstr_fd("bash: cd: OLDPWD not set\n", 2);
// 			return(-1);	
// 		}
// 	}
// 	return(0);
// }

// int	ft_check_cd_back(char **path, t_list *oldpwd)
// {
// 	if (**path == '-' && !*(*path + 1))
// 	{
// 		if (oldpwd)// && *oldpwd->value)
// 		{
// 			if (*oldpwd->value)
// 			*path = oldpwd->value;
// 		}
// 		else if (!oldpwd && g_help.on_oldpwd)
// 		{
// 			printf("cd - 2nd|%s|\n", g_help.old_pwd);
// 			if (g_help.old_pwd)
// 			{
// 				if (*g_help.old_pwd)
// 					*path = g_help.old_pwd;
// 			}
// 			else
// 			{
// 				ft_putstr_fd("bash: cd: OLDPWD not set\n", 2);
// 				return(-1);	
// 			}
// 		}
// 	while(1);
// 	}
// 	return(0);
// }

int		ft_cd_print_error(char *path)
{
	ft_putstr_fd("bash: cd: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

void	ft_cd_env_change_pwd(t_list *oldpwd, t_list *pwd)
{
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
	pwd->value = getcwd(NULL, 0);
}	

void	ft_cd_env_change(t_list *oldpwd, char *pwd_old)
{
	char *pfree;

	if (g_help.on_pwd)
	{
		if (oldpwd)
		{
			pfree =  oldpwd->value;
			oldpwd->value = ft_strdup(pwd_old);
			if (pfree)
				free(pfree);
		}
		else
		{
			//while (1);
			free(g_help.old_pwd);
			g_help.old_pwd = ft_strdup("");
			g_help.on_oldpwd = 1;	
		}
	}
	else
	{
		if (oldpwd)
		{
			pwd_old = oldpwd->value;
			oldpwd->value = ft_strdup("");	
			free(pwd_old);
		}// Asmaa verifie wash ghata7taji deri else
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
			return(-1);
	}
	oldpwd = ft_find_node(envl, "OLDPWD");
	pwd = ft_find_node(envl, "PWD");
	pwd_old = getcwd(NULL, 0);
//  traitement du chemin.
	if (ft_check_cd_back(path, oldpwd))
	{
		free(pwd_old);
		return(-1);
	}
	// int i = 0;
	// while(path[i])
	// {
	// 	printf("inside cd %d i\n", i);
	// 	printf("path %s \n", path[i]);
	// 	i++;
	// }
	ft_check_cd_home(path, envl);
	// while(1);
//	check for errors & change dir.
	if (chdir(*path) == -1 && ft_cd_print_error(*path))
	{
		free(pwd_old);
		return (-1);
	}
//	change env var value (pwd & oldpwd).
	if(ret == 5)
		ft_free(path);
	if (pwd)
		ft_cd_env_change_pwd(oldpwd, pwd);
	else
		ft_cd_env_change(oldpwd, pwd_old);
	// while(1);
	if (pwd_old)
		free(pwd_old);
	return(1);
}