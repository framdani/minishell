/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 13:56:33 by framdani          #+#    #+#             */
/*   Updated: 2021/06/02 13:57:05 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"
#include "../libft/libft.h"

void	free_lst_files(t_file **lst_files)
{
	t_file	*tmp;

	tmp = NULL;
	if (lst_files)
	{
		while (*lst_files)
		{
			tmp = (*lst_files)->next;
			free((*lst_files)->filename);
			free(*lst_files);
			*lst_files = tmp;
		}
		*lst_files = NULL;
	}
}

void	free_lst_args(t_arg		**lst_args)
{
	t_arg	*tmp;

	tmp = NULL;
	if (lst_args)
	{
		while (*lst_args)
		{
			tmp = (*lst_args)->next;
			free((*lst_args)->value);
			free(*lst_args);
			*lst_args = tmp;
		}
	}
}

void	free_lst_tokens(t_token **lst_tok)
{
	t_token	*tmp;

	tmp = NULL;
	if (lst_tok)
	{
		while (*lst_tok != NULL)
		{
			tmp = (*lst_tok)->next;
			free((*lst_tok)->value);
			free(*lst_tok);
			*lst_tok = tmp;
		}
	}
}

void	free_double_pointer(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

void	free_lst_cmds(t_cmd **lst_cmds)
{
	t_cmd	*tmp;

	tmp = NULL;
	if (lst_cmds)
	{
		while (*lst_cmds != NULL)
		{
			tmp = (*lst_cmds)->next;
			free_double_pointer((*lst_cmds)->args);
			free_lst_files(&(*lst_cmds)->file);
			free(*lst_cmds);
			*lst_cmds = tmp;
		}
	}
}
