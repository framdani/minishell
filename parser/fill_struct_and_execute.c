/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_and_execute.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:17:05 by framdani          #+#    #+#             */
/*   Updated: 2021/07/02 15:48:07 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"
#include "../libft/libft.h"
#include "../includes/minishell.h"

/*int 	is_valid_identifier(char *arg)
{
	int i;

	i = 0;
	if (ft_isdigit(arg[0]) || arg[0] == '\0' || arg[0] == '=')
		return (0);
	return (1);

}

t_envv	*get_key_value(char	*arg)
{
	t_envv		*envv;
	int			i;

	i = 0;
	envv->name=ft_strdup("");
	envv->value = ft_strdup("");
	if (!is_valid_identifier(arg))
	{
		free(envv->name);
		free(envv->value);
		return(NULL);
	}
	else
	{
		while (arg[i] != '=' && arg[i] != '\0')
		{
			if (arg[i] != '_' || !ft_isalnum(arg[i]))
			{
				free(envv->name);
				free(envv->value);
				return (NULL);
			}
			envv->name = ft_charjoin(envv->name, arg[i]);
			i++;
		}
		if (arg[i] == '=')
		{
			i++;
			while(arg[i] != '\0')
			{
				envv->value = ft_charjoin(envv->value, arg[i]);
				i++;
			}
		}
		else if (arg[i] == '\0')
		{
			envv->value = NULL;
		}
	}
	return (envv);
}*/

int	ft_lst_size(t_arg	*lst_arg)
{
	int		cmpt;
	t_arg	*tmp;

	cmpt = 0;
	tmp = lst_arg;
	while (tmp != NULL)
	{
		cmpt++;
		tmp = tmp->next;
	}
	return (cmpt);
}

char	**convert_into_dpointer(t_arg	**lst_arg)
{
	char	**arg;
	int		i;
	int		size;
	t_arg	*tmp;

	i = 0;
	tmp = *lst_arg;
	size = ft_lst_size(*lst_arg);
	arg = malloc(sizeof(char *) * (size + 1));
	if (!arg)
		return (NULL);
	while (tmp != NULL)
	{
		arg[i] = ft_strdup(tmp->value);
		i++;
		tmp = tmp->next;
	}
	arg[i] = 0;
	return (arg);
}

t_token 	*skip_token_space(t_token *tok)
{
	if (tok != NULL)
	{
		while (tok != NULL && tok->type == SPACE)
			tok = tok->next;
	}
	return (tok);
}

t_token	*fill_lst_args(t_arg **lst_args, t_token *tok)
{
	char	*arg;
	char	*tmp;

	arg = ft_strdup("");
	while (tok != NULL && tok->type == CHAR)
	{
		tmp = arg;
		arg = ft_strjoin(arg, tok->value);
		free(tmp);
		tok = tok->next;
	}
	add_arg(lst_args, arg);
	return (tok);
}

t_token	*fill_lst_files(t_file **lst_files, t_token *tok)
{
	char	*filename;
	char	*tmp;
	int	type;

	type = 0;
	filename = ft_strdup("");
	tmp = filename;
	if (tok->type == LEFT)
		type = 0;
	else if (tok->type == RIGHT)
		type = 1;
	else if (tok->type == GREATER)
		type = 2;
	else if (tok->type == LESSER)
		type = 3;
	tok = tok->next;
	while (tok != NULL && tok->type == CHAR)
	{
		tmp = filename;
		filename = ft_strjoin(filename, tok->value);
		tok = tok->next;
		free(tmp);
	}
	add_file(lst_files, filename, type);
	return (tok);
}

void	fill_struct_and_execute(t_token *lexer, t_list **envl)
{
	t_cmd	*lst_cmds;
	t_token	*tmp;
	t_arg	*lst_args;
	t_file	*lst_files;

	lst_args = NULL;
	lst_files = NULL;
	lst_cmds = NULL;
	tmp = lexer;
	//print_lexer(lexer);
	if (tmp != NULL)
	{
		tmp = skip_token_space(tmp);
		if (tmp != NULL && tmp->type == PIPE)
			tmp = tmp->next;
	}
	while (tmp != NULL)
	{
		if (tmp != NULL && tmp->type == CHAR)
			tmp = fill_lst_args(&lst_args, tmp);
		if (tmp != NULL && is_redirection(tmp->type))
			tmp = fill_lst_files(&lst_files, tmp);
		if (tmp != NULL && tmp->type == SPACE)
			tmp = skip_token_space(tmp);
		if (tmp != NULL && tmp->type == PIPE)
		{
			tmp = tmp->next;
			add_cmd(&lst_cmds, &lst_args, &lst_files);
			lst_files = NULL;
		}
		/*if (tmp != NULL && tmp->type == SEMICOLON)
		{
			tmp = tmp->next;
			//return value = execute();
			//free_lst_cmd();done
		}*/
	}
	if (lst_args != NULL || lst_files != NULL)
	{
		add_cmd(&lst_cmds, &lst_args, &lst_files);
		//print_struct(lst_cmds);
		ft_launch_execution(lst_cmds, envl);
	}
	free_lst_tokens(&lexer);
	free_lst_cmds(&lst_cmds);
}
