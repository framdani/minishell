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
int		main(int argc, char **argv)
{
	char *line;
	if (argc == 1)
	{
		printf("minishell$ ");
		while (get_next_line(0, &line))
		{
			if (strcmp(line, "exit") == 0)
			{
				printf("minishell$");
				return (0);
			}
			else {
				printf("minishell$ Apply smth");
			}
		}
	}
}
