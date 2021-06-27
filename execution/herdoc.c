/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:05:55 by akhalidy          #+#    #+#             */
/*   Updated: 2021/06/27 16:07:06 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_herdox(t_file *stp, char **envp)
{
	char	*line;
	int		fd;
	int		ret;

	line = NULL;
	fd = open("/tmp/file", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	while (1)
	{
		ft_putstr_fd("heredoc> ", 1);
		get_next_line(0, &line);
		if (!ft_strncmp(stp->filename, line, ft_strlen(stp->filename) + 1))
		{
			free(line);
			close(fd);
			break ;
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		ft_safe_free(line);
	}
	ret = ft_pipe(data, envp, APND);
	unlink("/tmp/file");
	return (ret);
}
