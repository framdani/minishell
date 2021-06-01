/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_pipe_sequence.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:57:16 by framdani          #+#    #+#             */
/*   Updated: 2021/05/25 17:57:19 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include "libft/libft.h"
#include <unistd.h>

void		add_arg(t_arg **lst_args, char *arg)
{
	t_arg	*new;
	t_arg	*tmp;

	new = malloc(sizeof(t_arg));
	if (new != NULL)
	{
		new->next = NULL;
		new->value = ft_strdup(arg);
		if (*lst_args == NULL)
			*lst_args = new;
		else
		{
			tmp = *lst_args;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
}

void		add_cmd(t_cmd **lst_cmds, t_arg **args, t_file **files)
{
	t_cmd	*new;
	t_cmd	*tmp;

	new = malloc(sizeof(t_cmd));
	if (new != NULL)
	{
		new->next = NULL;
		new->args = convert_into_dpointer(args);
		new->file = *files;
		//new->nbr_args = size(args);
		if (*lst_cmds == NULL)
			*lst_cmds = new;
		else
		{
			tmp = *lst_cmds;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
}

void		add_file(t_file **lst_files, char *filename, int type)
{

	t_file	*new;
	t_file	*tmp;

	new = malloc(sizeof(t_file));
	if (new != NULL)
	{
		new->next = NULL;
		new->filename = ft_strdup(filename);
		new->type = type;
		if (*lst_files == NULL)
			*lst_files= new;
		else
		{
			tmp = *lst_files;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
}

void	print_struct(t_cmd *lst_cmds)
{
	t_cmd		*tmp;
	char 		**arg;
	t_file		*files;
	int			i;

	tmp = lst_cmds;
	i = 0;
	//convert args into double pointer
	while (tmp != NULL)
	{
		i = 0;
		arg = tmp->args;
		ft_putstr_fd("cmds : \n", 1);
		if (arg)
		{
		while(arg[i] != NULL)
		{
			ft_putstr_fd("ARG : ", 1);
			ft_putstr_fd(arg[i], 1);
			ft_putstr_fd("\n", 1);
			i++;
		}
		}
		files = tmp->file;
		while (files!= NULL)
		{
			ft_putstr_fd("File : ", 1);
			ft_putstr_fd(files->filename, 1);
			ft_putstr_fd("\n", 1);
			ft_putstr_fd("Type : ", 1);
			ft_putchar_fd(files->type, 1);
			ft_putstr_fd("\n", 1);
			files = files->next;
		}
		tmp = tmp->next;
	}
	i = 0;
	if (arg)
	{
		while (arg[i])
		{
			free(arg[i]);
			i++;
		}
		free(arg);
	}
}
