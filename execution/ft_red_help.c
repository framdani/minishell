/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_red_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:50:12 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/10 12:32:55 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

void	ft_close(int fd)
{
	if (fd >= 0)
		close(fd);
}

void	ft_rd_print_error(char *path, int option)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	if (option)
		exit (1);
}

void	reset_stds(void)
{
	dup2(g_help.std_in, STDIN_FILENO);
	dup2(g_help.std_out, STDOUT_FILENO);
}

void	ft_free_envv(t_list **env, t_envv **envv)
{
	if ((*envv)->value)
	{
		free((*env)->value);
		(*env)->value = (*envv)->value;
	}
	free((*envv)->name);
}

void	ft_her_doc_help(t_file *lst, t_list **env)
{
	int		fd;
	char	*line;
	char 	*val;

	signal(SIGINT, handler_3);
	signal(SIGQUIT, handler_3);
	fd = open("/tmp/file", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	while (1)
	{
		line = readline(">");
		if (!line)
			break ;
		val = remove_quotes(lst->filename);
		if (!ft_strncmp(val, line, ft_strlen(val) + 1))
		{
			free(line);
			free(val);
			close(fd);
			break ;
		}
		if (!quote_exist(lst->filename))
			line = parse_line_hd(line, env);
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
}
