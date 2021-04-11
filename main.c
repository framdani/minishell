/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:41:12 by framdani          #+#    #+#             */
/*   Updated: 2021/03/30 12:41:14 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "get_next_line.h"
#define EXIT 0
#define TRUE 1
int		main()
{
	char	*line;
	int		status;

	status = 1;
	while (status)
	{
			//start the shell => initialize
			write(1, "minishell$ ",11);
			while (get_next_line(0, &line))
			{
				if (strcmp(line, "exit") == 0)
				{
					write(1, "exit", 4);
					status = 0;
					break;
				}
				else
				{
					//Read the command
					//parse the command
					//Run the command
					write(1, "minishell$ ", 11);
				}
				free(line);
			}
	}
}
