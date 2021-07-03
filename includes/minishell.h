/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:22:12 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/03 12:57:54 by akhalidy         ###   ########.fr       */
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

typedef struct s_global
{
	char	*old_pwd;
	char	*pwd;
	int		on_pwd;
	int		on_oldpwd;
	int		ret;
	int		std_in;
	int		std_out;
}			t_global;

typedef struct s_envv
{
	char	*name;
	char	*value;
}			t_envv;

typedef struct s_exec_hlp
{
	int		status;
	int		ret;
	int		id;
}			t_exec_hlp;

char	*get_env(char *env, t_list **envl);
void	ft_echo(char **args, int fd);
void	ft_env(t_list *envl, int fd);
void	ft_export(t_list **envl, char **args, int fd);
void	ft_unset(t_list **envl, char **args);
int		ft_cd(t_list *envl, char **path);
int		ft_cd_print_error(char *path);
void	ft_pwd(t_list *envl);
void	ft_inc_shlvl(t_list *envl);
int		ft_exec_cmd(t_list *envl, char **args, int fork);
int		ft_launch_exec(char **args, t_list **envl, int fork);
void	ft_exit(char **args);
int		ft_redirect(t_file *fil_lst, int fd[2], int option, t_list **env);
void	ft_fork_pipe(int *io, char **args, t_list **envl, int *pid);
void	ft_set_io(int *fd_io, int *io, int out);
int		ft_pipe(t_cmd *lst, t_list **envl);
int		ft_wait_loop(t_cmd	*cmds);
int		ft_red_smpl_cmd(t_cmd *cmds, t_list **envl);
void	ft_launch_execution(t_cmd *cmds, t_list	**envl);
int		ft_red_smpl_cmd(t_cmd *cmds, t_list **envl);
void	ft_pipe_help(int fd[2], int io[3], int *k);
void	ft_initialize(int io[3], t_cmd	**new, t_cmd **lst, int *k);
void	ft_exit_child(void);
void	reset_stds(void);
int		ft_cd_print_error(char *path);
void	set_pwd_oldpwd(t_list *envl, char *pwd_old);
void	ft_check_cd_home(char **path, t_list *envl);
int		ft_check_cd_void(char ***path, t_list *home);
void	ft_close(int fd);
void	ft_rd_print_error(char *path, int option);
void	reset_stds(void);
t_global	g_help;

#endif
