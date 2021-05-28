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
			print_struct(lst_cmds);
			tmp=tmp->next;
			//execute();
		}
		//if (tmp != NULL)
		//	tmp = tmp->next;
	}
		add_cmd(&lst_cmds, &lst_args, &lst_files);
		print_struct(lst_cmds);
}
