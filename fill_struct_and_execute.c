/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_and_execute.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:17:05 by framdani          #+#    #+#             */
/*   Updated: 2021/05/28 15:17:18 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"
#include "libft/libft.h"

/*int 	is_valid_identifier(char *arg)
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
			envv->name = ft_charjoin(envv->name, arg[i]);
			i++;
		}
		if (arg[i] == '=')
		{
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
}*/

int	ft_lst_size(t_arg	*lst_arg)
{
	int		cmpt;
	t_arg	*tmp;

	cmpt = 0;
	tmp = lst_arg;
	while (tmp != NULL)
	{
		cmpt++;
		tmp = tmp->next;
	}
	return (cmpt);
}

char	**convert_into_dpointer(t_arg	**lst_arg)
{
	char	**arg;
	int		i;
	int		size;
	t_arg	*tmp;

	i = 0;
	tmp = *lst_arg;
	size = ft_lst_size(*lst_arg);
	arg = malloc(sizeof(char *) * (size + 1));
	if (!arg)
		return (NULL);
	while (tmp != NULL)
	{
		arg[i] = ft_strdup(tmp->value);
		i++;
		tmp = tmp->next;
	}
	arg[i] = 0;
	return (arg);
}

void	fill_struct_and_execute(t_token *lexer)
{
	t_cmd				*lst_cmds;
	t_token				*tmp;
	char				*arg;
	char				*filename;
	int					type;

	t_arg	*lst_args =  NULL;
		//init_args();
	//lst_cmds.args = &lst_args;
	t_file	*lst_files = NULL;
	lst_cmds = NULL;
		//init_file();
	//lst_cmds.file = &lst_files;
	tmp = lexer;
	filename = ft_strdup("");
	arg = ft_strdup("");
	type = 0;
	if (tmp != NULL)
	{
		while (tmp != NULL && tmp->type == SPACE)
			tmp = tmp->next;
		if (tmp != NULL && is_separator(tmp->type))
			tmp = tmp->next;
	}
	while (tmp != NULL)
	{
		if (tmp != NULL && tmp->type == CHAR)
		{
			arg = ft_strdup("");
			while (tmp != NULL && tmp->type == CHAR)
			{
				arg = ft_strjoin(arg, tmp->value);
				tmp = tmp->next;
			}
			add_arg(&lst_args, arg);
		}
		if (tmp != NULL && is_redirection(tmp->type))
		{
			filename = ft_strdup("");
			if (tmp->type == LEFT)
				type = 0;
			else if (tmp->type == RIGHT)
				type = 1;
			else if (tmp->type == GREATER)
				type = 2;
			tmp = tmp->next;
			while( tmp!= NULL && tmp->type == CHAR)
			{
				filename = ft_strjoin(filename, tmp->value);
				tmp = tmp->next;
			}
			add_file(&lst_files, filename, type);
		}
		if (tmp != NULL && tmp->type == SPACE)
		{
			while(tmp != NULL && tmp->type == SPACE)
				tmp = tmp->next;
		}
		if (tmp != NULL && tmp->type == PIPE)
		{
			tmp=tmp->next;
			add_cmd(&lst_cmds, &lst_args, &lst_files);
			lst_args = NULL;
			lst_files = NULL;
		}
		if (tmp != NULL && tmp->type == SEMICOLON)
		{
			tmp = tmp->next;
			//execute();
			//free_lst_cmd();
		}
	}
	if (lst_args != NULL || lst_files != NULL)
	{
		add_cmd(&lst_cmds, &lst_args, &lst_files);
		print_struct(lst_cmds);
		//execute
	}
	free_lst_cmds(&lst_cmds);
}
