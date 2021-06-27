/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:22:12 by akhalidy          #+#    #+#             */
/*   Updated: 2021/06/25 17:46:57 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/param.h>
# include <sys/errno.h>
# include <dirent.h>
# include "../libft/libft.h"
# include "parser.h"

typedef struct	s_global
{
	char	*old_pwd;
	char	*pwd;
	int		on_pwd;
	int		on_oldpwd;
	int		ret;
	int		std_in;
	int		std_out;
}				t_global;

typedef struct		s_envv
{
	char		*name;
	char		*value;
}				t_envv;

//parsing
// void	print_error(char *error);
// int 	ft_strstrlen(char **str);
// int 	ft_str_one_char(char *str, char c);
// void	ft_strtolower(char **str);

//help function
// void	bubblesort(char *arr[], int n);
// void	ft_lstbubblesort(t_list	*lst);
// void	ft_swap_str(char **str1, char **str2);
// char	**ft_list_to_arr(t_list *lst);
// t_list	*ft_arr_to_list(char **str);
// void	ft_print_list(t_list *lst); // To ajust the result with env behaviour, this function only 
// 									// print env with a value != '/0'.
// void	ft_putstrstr_fd(char **str, int fd);

//main functions
void	ft_echo(char **args, int fd);
void	ft_env(t_list *envl, int fd);
void	ft_export(t_list **envl, char **args, int fd);
void	ft_unset(t_list **envl, char **args);
int		ft_cd(t_list *envl, char **path);
int		ft_cd_print_error(char *path);
void	ft_pwd(t_list *envl);
void	ft_inc_shlvl(t_list *envl);
int		ft_exec_cmd(t_list *envl, char **args, int fork);
int		ft_launch_exec(char **args, t_list *envl, int fork);
void	ft_exit(char **args);
int		ft_redirect(t_file *fil_lst, int *fd_in, int *fd_out, int option);
void	ft_fork_pipe(int *io, char **args, t_list *envl, int *pid);
void	ft_set_io(int *fd_io, int *io, int out);
int		ft_pipe(t_cmd *lst, t_list *envl);
void    reset_stds(void);
int		ft_wait_loop(t_cmd	*cmds);
void	ft_exit_child(void);
// tmp function parsing ones
void	add_file(t_file **lst_files, char *filename, int type);
void	ft_fill_cmd_tst(char **args, t_cmd **cmds);
void	free_lst_files(t_file **lst_files);
void	ft_cmd_delone(t_cmd *lst);
void	ft_cmd_clear(t_cmd **lst);
void	ft_print_cmd_list(t_cmd *lst);
void	ft_add_file_tmp(t_cmd *cmds);
int		ft_red_smpl_cmd(t_cmd *cmds, t_list *envl);
void 	free_lst_cmds(t_cmd **lst_cmds);

void	ft_launch_execution(t_cmd *cmds, t_list	*envl);
int		ft_red_smpl_cmd(t_cmd *cmds, t_list *envl);
t_global	g_help;
#endif
