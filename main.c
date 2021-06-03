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

void	prompt(void)
{
	char	*str;

	str = ft_strdup("\033[0;33mminishell$ \033[0m");
	write(1, str, ft_strlen(str));
	free(str);
}

char	*read_command_line(void)
{
	char	*line_cmd;
	char	*buff;

	buff = malloc(1);
	line_cmd = ft_strdup("");
	while (read(0, buff, 1))
	{
		if (buff[0] == '\n')
		{
			free(buff);
			return (line_cmd);
		}
		line_cmd = ft_charjoin(line_cmd, buff[0]);
	}
	free(buff);
	return (line_cmd);
}

void	print_lexer(t_token *lexer)
{
	t_token	*tmp;

	tmp = lexer;
	while (tmp != NULL)
	{
		printf("TOKEN (%s,%d)\n", tmp->value, tmp->type);
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv, char **env)
{
	char		*cmd_line;
	int			status;
	t_token		*tokens;
	int			size;

	argc = 0;
	argv = NULL;
	status = 1;
	size = 0;
	env = NULL;
	//return value = 0;
	while (status)
	{
		prompt();
		cmd_line = read_command_line();
		size = ft_strlen(cmd_line) + 1;
		tokens = lexer(cmd_line, size);
		tokens = parser(tokens);
		//if (size > 0 && tokens != NULL)
			//set_return_value
		fill_struct_and_execute(tokens);
		if (strcmp(cmd_line, "exit") == 0)
		{
			write(1, "exit", 4);
			status = 0;
			free(cmd_line);
			system("leaks minishell");
			break ;
		}
		system("leaks minishell");
		free(cmd_line);
	}
}
