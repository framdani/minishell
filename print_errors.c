/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:51:26 by framdani          #+#    #+#             */
/*   Updated: 2021/05/21 16:51:32 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include "includes/lexer.h"
#include "libft/libft.h"
#include <stdlib.h>

void	print_error(char *str)
{
	ft_putstr_fd(str, 1);
}
