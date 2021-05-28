/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 19:15:19 by framdani          #+#    #+#             */
/*   Updated: 2021/05/28 19:15:22 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"
#include "includes/parser.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./includes/lexer.h"

t_arg		init_args(void)
{
	t_arg	lst_arg;

	lst_arg.value = NULL;
	lst_arg.next = NULL;
	return (lst_arg);
}

t_file		init_file(void)
{
	t_file lst_file;

	lst_file.filename = NULL;
	lst_file.type = 0;
	lst_file.next = NULL;
	return (lst_file);
}

/*t_cmd	init_cmd(void)
{
	t_cmd lst_cmds ;

	lst_cmds.args = init_args();
	lst_cmds.file = init_file();
	lst_cmds->nbr_args = 0;
	lst_cmds->next = NULL;
	return (lst_cmds);
}*/
