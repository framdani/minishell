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
int		main(int argc, char **argv)
{
	char	*line;
	int		test;

	test = 1;
	while (test)
	{
		if (argc == 1)
		{
			//start the shell
			write(1, "minishell$ ",10);
			while (get_next_line(0, &line))
			{
				if (strcmp(line, "exit") == 0)
				{
					write(1, "exit", 4);
					test = 0;
					break;
				}
				else
				{
					//parse the user input
					write(1, "minishell$ ", 10);
				}
			}
		}
		else
		{
			printf("Error");
			test = 0;
		}
	}
}
