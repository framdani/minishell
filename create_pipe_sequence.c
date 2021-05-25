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
#include "includes/lexer.h"
#include "includes/parser.h"
#include "libft/libft.h"
#include <stdlib.h>

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

void		add_cmd(t_cmd **lst_cmds, char *name, t_arg *args)
{
	t_cmd	*new;
	t_cmd	*tmp;

	new = malloc(sizeof(t_cmd));
	if (new != NULL)
	{
		new->next = NULL;
		new->name = ft_strdup(name);
		new->args = args;
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

t_pipe_sequence		*new_pipe_sequence(t_token *lexer)
{
	t_pipe_sequence		*pipe_seq;
	t_cmd				*cmds;
	t_arg				*args;
	char				*name;

	cmds = NULL;
	args = NULL;
	pipe_seq = NULL;
	name = "";
	while (lexer != NULL)
	{
		//if (lexer->type == SEMICOLON)
			//{execution; free;return to lexer}
		//else if (lexer->type == PIPE)
			//{add_cmd};
		//else if (lexer->type == CHAR)
		//lexer = lexer->next;
	}
	return pipe_seq;
	//pipe_seq->cmds = lstof commands;
	//pipe_seq->nbr = nbr of pipes
}

