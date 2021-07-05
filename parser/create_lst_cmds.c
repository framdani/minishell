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

#include "../includes/parser.h"
#include "../libft/libft.h"
#include <unistd.h>

void	add_arg(t_arg **lst_args, char *arg)
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
	free(arg);
}

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

void	add_cmd(t_cmd **lst_cmds, t_arg **args, t_file **files)
{
	t_cmd	*new;
	t_cmd	*tmp;

	new = malloc(sizeof(t_cmd));
	if (new != NULL)
	{
		new->next = NULL;
		new->args = convert_into_dpointer(args);
		free_lst_args(args);
		new->file = *files;
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

void	add_file(t_file **lst_files, char *filename, int type)
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
			*lst_files = new;
		else
		{
			tmp = *lst_files;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
	free(filename);
}
