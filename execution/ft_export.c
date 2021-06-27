/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:39:05 by akhalidy          #+#    #+#             */
/*   Updated: 2021/06/26 16:33:39 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*char 	*ft_charjoin(char 	*str, char c)
{
	int 	length;
	int 	i;
	char 	*res;

	length = 0;
	i = 0;
	if (str)
		length = ft_strlen(str);
	if (!(res = malloc(length + 2)))
		return (NULL);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = c;
	res[i + 1] = '\0';
	free(str);
	return (res);
}*/

int 	is_valid_identifier(char *arg)
{
	int i;
	i = 0;
	if (ft_isdigit(arg[0]) || arg[0] == '\0' || arg[0] == '=')
		return (0);
	return (1);
}
t_envv	*get_key_value(char	*arg)
{
	t_envv		*envv;
	int			i;

	i = 0;
	envv = malloc(sizeof(t_envv));
	envv->name=ft_strdup("");
	envv->value = ft_strdup("");
	if (!is_valid_identifier(arg))
	{
		free(envv->name);
		free(envv->value);
		return(NULL);
	}
	else
	{
		while (arg[i] != '=' && arg[i] != '\0')
		{
			if (arg[i] != '_' && !ft_isalnum(arg[i]))
			{
				free(envv->name);
				free(envv->value);
				return (NULL);
			}
			envv->name = ft_charjoin(envv->name, arg[i]);
			i++;
		}
		if (arg[i] == '=')
		{
			i++;
			while(arg[i] != '\0')
			{
				envv->value = ft_charjoin(envv->value, arg[i]);
				i++;
			}
		}
		else if (arg[i] == '\0')
		{
			envv->value = NULL;
		}
	}
	return (envv);
}

void	ft_export_add(t_list **envl, char **args)
{
	char	**split;
	char	*pfree;
	t_list	*env;
	t_envv	*envv;
	int		i;

	i = 0;
	while (args[i])
	{
		envv = get_key_value(args[i]);
		if (!envv)
		{
			ft_putendl_fd("not a valid identifier", 2);
			return;
		}
		env = ft_find_node(*envl, envv->name);
		if (env)
		{
			if (envv->value)
			{
				pfree = env->value;
				env->value = envv->value;
				free(pfree);
			}
			free(envv->name);
		}
		else
			ft_lstadd_back(envl, ft_lstnew(envv->name, envv->value));
		free(envv);
		i++;
	}
}

void	ft_export(t_list **envl, char **args, int fd)
{
	t_list	*head;
	
	head = *envl;
	if (!*args)
	{
		ft_lstbubblesort(head);
		while (head)
		{
			ft_putstr_fd("declare -x ",fd);
			ft_putstr_fd(head->env, fd);
			if (head->value)
			{
				ft_putstr_fd("=\"", fd);
				ft_putstr_fd(head->value, fd);
				ft_putstr_fd("\"\n", fd);
			}
			else
				ft_putstr_fd("\n", fd);
			head = head->next;
		}
	}
	else
		ft_export_add(&head, args);
}
