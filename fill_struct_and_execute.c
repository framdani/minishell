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
#include "includes/parser.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./includes/lexer.h"

int		ft_lst_size(t_arg	*lst_arg)
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
	if (!(arg = malloc(sizeof(char *) * (size + 1))))
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
		while (tmp->type == SPACE)
			tmp = tmp->next;
		if (tmp->type == SEMICOLON || tmp->type == PIPE)
			tmp = tmp->next;
	}
	while (tmp != NULL)
	{
		if (tmp->type == CHAR)
		{
			arg = ft_strdup("");
			while (tmp != NULL && tmp->type == CHAR)
			{
				arg = ft_strjoin(arg, tmp->value);
				tmp = tmp->next;
			}
			add_arg(&lst_args, arg);
			free(arg);
		}
		if (tmp != NULL && (tmp->type == LEFT || tmp->type == RIGHT || tmp->type == GREATER))
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
			free(filename);
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
			add_cmd(&lst_cmds, &lst_args, &lst_files);
			print_struct(lst_cmds);
			tmp=tmp->next;
			//execute();
		}
	}
		add_cmd(&lst_cmds, &lst_args, &lst_files);
		print_struct(lst_cmds);
		//execute
}
