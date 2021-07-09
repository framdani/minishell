/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 20:49:30 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/08 17:11:44 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

void	handler(int c)
{
	if (g_help.in_here_doc && !g_help.in_child)
	{
		g_help.in_here_doc = -1;
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (c == SIGINT && g_help.in_child)
	{
		write(1, "\n", 1);
		rl_on_new_line();
	}
	else if (c == SIGINT && !g_help.in_child)
	{
		g_help.ret = 1;
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	handler_2(int c)
{
	if (c == SIGQUIT && g_help.in_child && !g_help.in_here_doc)
	{
		write(1, "Quit: 3\n", 8);
		rl_on_new_line();
	}
	else if (c == SIGQUIT && !g_help.in_child)
	{
		rl_on_new_line();
		rl_redisplay();
		return ;
	}
}

void	handler_3(int c)
{
	if (c == SIGINT)
		exit (254);
	else if (c == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}
