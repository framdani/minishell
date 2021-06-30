/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_hd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:47:07 by framdani          #+#    #+#             */
/*   Updated: 2021/06/29 19:16:13 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/parser.h"

char 	*parse_line_hd(char *input, t_list **envl)
{
	int i;
	char *ret;
	char *to_expand;
	char *new_value;
	char *pfree;

	i = 0;
	ret = ft_strdup("");
	//to_expand = ft_strdup("");
	//new_value = ft_strdup("");
	while (input[i] != '\0')
	{
		if (input[i] == '$')
		{
			i++;
			if (ft_isdigit(input[i]))
				i++;
			else if (ft_isalpha(input[i]) || input[i] == '_')
			{
				to_expand = ft_strdup("");
				while (ft_isalnum(input[i]) || input[i] == '_')
				{
					to_expand = ft_charjoin(to_expand, input[i]);
					i++;
				}
				//new_value = ft_strdup("");
				new_value = get_env(to_expand, envl);
				free(to_expand);
				if (new_value != NULL)
				{
					pfree = ret;
					ret = ft_strjoin(ret, new_value);
					free(pfree);
				}
				//free(new_value);
			}
		}
		else
		{
			ret = ft_charjoin(ret, input[i]);
			i++;
		}
	}
	free(input);
	return (ret);
}