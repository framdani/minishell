/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 12:16:06 by akhalidy          #+#    #+#             */
/*   Updated: 2021/06/27 17:34:40 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

int	ft_redirect(t_file *fil_lst, int *fd_in, int *fd_out, int option)
{
	t_file  *lst;
	int		tmp;
	char	*line;
	int		fd;
	
	*fd_in = -18;
	*fd_out = -18;
	lst = fil_lst;
	if (!lst)
		return(-1);
	while (lst)
	{
		if (!lst->type)
		{
			tmp = *fd_in;
			*fd_in = open(lst->filename, O_RDONLY);
			if (*fd_in == -1)
			{
				ft_close(tmp);
				ft_close(*fd_out);
				ft_rd_print_error(lst->filename, option);
				return (0);
			}
			ft_close(tmp);
		}
		else if (lst->type == 3)
		{
			
			tmp = *fd_in;
			fd = open("/tmp/file", O_CREAT | O_TRUNC | O_WRONLY, 0644);
			while (1)
			{
				ft_putstr_fd("> ", 1);
				get_next_line(0, &line);
				if (!ft_strncmp(lst->filename, line, ft_strlen(lst->filename) + 1))
				{
					free(line);
					close(fd);
					break ;
				}
			//framdani fonction to chech for any env var!
				write(fd, line, ft_strlen(line));
				write(fd, "\n", 1);
				free(line);
			}
			*fd_in = open("/tmp/file", O_RDONLY);
			ft_close(tmp);
		}
		else
		{
			tmp = *fd_out;
			if (lst->type == 1)
				*fd_out = open(lst->filename, O_CREAT | O_TRUNC | O_WRONLY, 0644);
			else
				*fd_out = open(lst->filename, O_CREAT | O_APPEND | O_WRONLY, 0644);
			if (*fd_out == -1)
			{
				ft_close(tmp);
				ft_close(*fd_in);
				ft_cd_print_error(lst->filename);
				return (0);
			}
			ft_close(tmp);
		}	
		lst = lst->next;
	}
	return(1);
}

void    reset_stds(void)
{
	dup2(g_help.std_in, STDIN_FILENO);
	dup2(g_help.std_out, STDOUT_FILENO);
}
