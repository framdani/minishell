/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lst_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <framdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:55:17 by framdani          #+#    #+#             */
/*   Updated: 2021/07/05 15:50:48 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"
#include "../libft/libft.h"
#include "../includes/minishell.h"

t_token	*skip_token_space(t_token *tok)
{
	if (tok != NULL)
	{
		while (tok != NULL && tok->type == SPACE)
			tok = tok->next;
	}
	return (tok);
}

t_token	*fill_lst_args(t_arg **lst_args, t_token *tok)
{
	char	*arg;
	char	*tmp;

	arg = ft_strdup("");
	while (tok != NULL && tok->type == CHAR)
	{
		tmp = arg;
		arg = ft_strjoin(arg, tok->value);
		free(tmp);
		tok = tok->next;
	}
	add_arg(lst_args, arg);
	return (tok);
}

t_token	*fill_lst_files(t_file **lst_files, t_token *tok)
{
	char	*filename;
	char	*tmp;
	int		type;

	type = 0;
	filename = ft_strdup("");
	tmp = filename;
	if (tok->type == LEFT)
		type = 0;
	else if (tok->type == RIGHT)
		type = 1;
	else if (tok->type == GREATER)
		type = 2;
	else if (tok->type == LESSER)
		type = 3;
	tok = tok->next;
	while (tok != NULL && tok->type == CHAR)
	{
		tmp = filename;
		filename = ft_strjoin(filename, tok->value);
		tok = tok->next;
		free(tmp);
	}
	add_file(lst_files, filename, type);
	return (tok);
}

t_token	*init_lists(t_token *lexer, t_cmd **lst_cmds, t_arg **lst_args,
	t_file **lst_files)
{
	*lst_args = NULL;
	*lst_cmds = NULL;
	*lst_files = NULL;
	if (lexer != NULL)
	{
		lexer = skip_token_space(lexer);
		/*if (lexer != NULL && lexer->type == PIPE)
		{
			lexer = lexer->next;
			//return (NULL);
		}*/
	}
	return (lexer);
}

t_cmd	*fill_struct(t_token *lexer)
{
	t_cmd	*lst_cmds;
	t_token	*tmp;
	t_arg	*lst_args;
	t_file	*lst_files;

	tmp = init_lists(lexer, &lst_cmds, &lst_args, &lst_files);
	while (tmp != NULL)
	{
		if (tmp != NULL && tmp->type == CHAR)
			tmp = fill_lst_args(&lst_args, tmp);
		if (tmp != NULL && is_redirection(tmp->type))
			tmp = fill_lst_files(&lst_files, tmp);
		if (tmp != NULL && tmp->type == SPACE)
			tmp = skip_token_space(tmp);
		if (tmp != NULL && tmp->type == PIPE)
		{
			tmp = tmp->next;
			add_cmd(&lst_cmds, &lst_args, &lst_files);
			lst_files = NULL;
		}
	}
	if (lst_args != NULL || lst_files != NULL)
		add_cmd(&lst_cmds, &lst_args, &lst_files);
	return (lst_cmds);
}
