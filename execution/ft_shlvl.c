/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shlvl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 12:28:00 by akhalidy          #+#    #+#             */
/*   Updated: 2021/06/08 19:01:46 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_inc_shlvl(t_list *envl)
{
	t_list	*prev_shlvl;
	char	*pfree;

	prev_shlvl = ft_prev_node(envl, "SHLVL");
	pfree = (prev_shlvl->next)->value;
	(prev_shlvl->next)->value = ft_itoa(ft_atoi((prev_shlvl->next)->value) + 1);
	free(pfree);
}
