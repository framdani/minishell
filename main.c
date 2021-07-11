/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <framdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:41:12 by framdani          #+#    #+#             */
/*   Updated: 2021/07/11 16:08:18 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/parser.h"
#include "libft/libft.h"
#include "./includes/minishell.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
// #include <readline/rl_replace_line.h>
/*char	*read_command_line(void)
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
}*/
void	print_struct(t_cmd *lst_cmds)
{
	t_cmd		*tmp;
	char		**arg;
	t_file		*files;
	int			i;

	tmp = lst_cmds;
	i = 0;
	while (tmp != NULL)
	{
		i = 0;
		arg = tmp->args;
		ft_putstr_fd("cmds : \n", 1);
		if (arg)
		{
			while (arg[i] != NULL)
			{
				ft_putstr_fd("ARG : ", 1);
				ft_putstr_fd(arg[i], 1);
				ft_putstr_fd("\n", 1);
				i++;
			}
		}
		files = tmp->file;
		while (files != NULL)
		{
			ft_putstr_fd("File : ", 1);
			ft_putstr_fd(files->filename, 1);
			ft_putstr_fd("\n", 1);
			ft_putstr_fd("Type : ", 1);
			ft_putchar_fd(files->type, 1);
			ft_putstr_fd("\n", 1);
			files = files->next;
		}
		tmp = tmp->next;
	}
}

void	print_lexer(t_token *lexer)
{
	t_token	*tmp;

	tmp = lexer;
	while (tmp != NULL)
	{
		printf(" (%s,%d)\n", tmp->value, tmp->type);
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv, char **env)
{
	t_list		*envl;
	char		*cmd_line;
	int			status;
	t_token		*tokens;
	t_cmd		*lst_cmds;
	int size = 0;
	argc = 0;
	argv = NULL;
	status = 1;
	
	g_help.on_oldpwd = 1;
	g_help.on_pwd = 1;
	g_help.in_child = 0;
	g_help.in_here_doc = 0;
	g_help.std_in = dup(STDIN_FILENO);
	g_help.std_out = dup(STDOUT_FILENO);
	envl = ft_arr_to_list(env);
	ft_inc_shlvl(envl);
	while (status)
	{
		signal(SIGINT, handler);
		signal(SIGQUIT, handler_2);
		cmd_line = readline("minishell$ ");
		if (cmd_line == NULL)
		{
			ft_putstr_fd("\033[Aminishell$ exit\n", 1);
			exit(g_help.ret);
		}
			if (*cmd_line != '\0')
				add_history(cmd_line);
			size = ft_strlen(cmd_line) + 1;
			tokens = lexer(cmd_line, size, &envl);
			//print_lexer(tokens);
			tokens = parser(tokens);
			lst_cmds = fill_struct(tokens);
			//print_struct(lst_cmds);
			if (lst_cmds != NULL)
				ft_launch_execution(lst_cmds, &envl);
			//system("leaks minishell");
		//free(cmd_line);
			free_lst_tokens(&tokens);
			free_lst_cmds(&lst_cmds);
		free(cmd_line);
	}
}
