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

void	prompt()
{
	char *str;

	str = ft_strdup("\033[0;33mminishell$ \033[0m");
	write(1, str, ft_strlen(str));
}

char *read_command_line(void)
{
	char	*line_cmd;
	char	*buff;

	buff = malloc(1);
	line_cmd = ft_strdup("");
	while (read(0, buff, 1))
	{
		if(buff[0] == '\n')
		{
			free(buff);
			return (line_cmd);
		}
		line_cmd = ft_charjoin(line_cmd, buff[0]);
	}
	free(buff);
	return (line_cmd);
}

void		print_lexer(t_token *lexer)
{
	t_token *tmp = lexer;
	while (tmp != NULL)
	{
		printf("TOKEN (%s,%d)\n", tmp->value, tmp->type);
		tmp = tmp->next;
	}
}

/*static	int is_builtin_command(char *cmd)
{
	const char *cmds[8] = {"echo", "cd", "pwd", "export", "unset", "env",
		"exit", "history"};
	int i = 0;
	while (i < 8)
	{
		if (strcmp(cmd, cmds[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}*/

int		main(int argc, char **argv, char **env)
{
	char		*cmd_line;
	int			status;
	t_token		*tokens;

	argc = 0;
	argv = NULL;
	status = 1;

	env = NULL;
	while (status)
	{
			//start the shell => initialize
		prompt();
		cmd_line = read_command_line();
			//record in history//in a file
		tokens = lexer(cmd_line);
		parser(tokens);
		fill_struct_and_execute(tokens);
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
// Rules for naming variable name : it must begin with alphanemuric or underscore
// if the flag is not specified print the flag as it
