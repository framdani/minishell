/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:41:12 by framdani          #+#    #+#             */
/*   Updated: 2021/04/26 17:19:50 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	prompt()
{
	write(1, "minishell$ ", 11);
}

static char *read_command_line(void)
{
	char	*line_cmd;

	line_cmd = NULL;
	get_next_line(0, &line_cmd);
	return (line_cmd);
}

static	int is_builtin_command(char *cmd)
{
	const char *cmds[8] = {"echo", "cd", "pwd", "export", "unset", "env",
		"exit", "history"};
	int i = 0;
	while (i < 8)
	{
		//printf("|%s|, |%s|, |%d|\n", cmd, cmds[i], strcmp(cmd, cmds[i]));
		if (strcmp(cmd, cmds[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int		main(int argc, char **argv, char **env)
{
	char	*cmd_line;
	int		status;
	char	*path;

	argc = 0;
	argv = NULL;
	status = 1;
	path = getenv("PATH");

	*env = NULL;
	//init env_var
	while (status)
	{
			//start the shell => initialize
			prompt();
			cmd_line = read_command_line();
			//record in history//in a file
			//build_lexer(cmd_line);
			//parse
			//create abstract syntax tree
			//execution
			if (is_builtin_command(cmd_line))
				write(1,"recode\n", 7);
			else
				printf("search binary on path\n");
			if (strcmp(cmd_line, "exit") == 0)
			{
				write(1, "exit", 4);
				status = 0;
				free(cmd_line);
				break;
			}
			free(cmd_line);
	}
}

// |; ||;| syntax error near unexpected token
