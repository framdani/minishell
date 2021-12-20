/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:41:12 by framdani          #+#    #+#             */
/*   Updated: 2021/12/20 10:56:12 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/parser.h"
#include "libft/libft.h"
#include "includes/minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

void	catch_eof(void)
{
	char	*cm_cap;

	cm_cap = tgetstr("up", NULL);
	tputs(tgoto(cm_cap, 0, 0), 0, putchar);
	printf("minishell$ exit\n");
	exit(g_help.ret);
}

t_list	*ft_init(char **env, char **argv, int argc)
{
	t_list	*envl;

	argc = 0;
	argv = NULL;
	g_help.on_oldpwd = 1;
	g_help.on_pwd = 1;
	g_help.in_child = 0;
	g_help.in_here_doc = 0;
	g_help.std_in = dup(STDIN_FILENO);
	g_help.std_out = dup(STDOUT_FILENO);
	envl = ft_arr_to_list(env);
	ft_inc_shlvl(envl);
	return (envl);
}

t_cmd	*parse(char *cmd_line, t_list **envl)
{
	t_cmd	*lst_cmds;
	t_token	*tokens;
	int		size;

	size = ft_strlen(cmd_line) + 1;
	tokens = lexer(cmd_line, size, envl);
	tokens = parser(tokens);
	lst_cmds = fill_struct(tokens);
	free_lst_tokens(&tokens);
	free(cmd_line);
	return (lst_cmds);
}

int	main(int argc, char **argv, char **env)
{
	t_list		*envl;
	char		*cmd_line;
	t_cmd		*lst_cmds;

	envl = ft_init(env, argv, argc);
	while (1)
	{
		signal(SIGINT, handler);
		signal(SIGQUIT, handler_2);
		cmd_line = readline("minishell$ ");
		if (cmd_line == NULL)
			catch_eof();
		if (*cmd_line != '\0')
			add_history(cmd_line);
		lst_cmds = parse(cmd_line, &envl);
		if (lst_cmds != NULL)
			ft_launch_execution(lst_cmds, &envl);
		free_lst_cmds(&lst_cmds);
		// system("leaks minishell");
	}
}
