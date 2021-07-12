/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:22:12 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/12 15:01:00 by akhalidy         ###   ########.fr       */
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
	int		on_oldpwd;
	int		on_pwd;
	int		std_out;
	int		std_in;
	int		in_child;
	int		in_here_doc;
	int		ret;
}			t_global;

typedef struct s_exec_hlp
{
	int		status;
	int		ret;
	int		id;
}			t_exec_hlp;

typedef struct s_cd_hlp
{
	t_list	*oldpwd;
	t_list	*pwd;
	char	*pwd_old;
	char	*tmp;
	int		ret;
}			t_cd_hlp;

typedef struct s_pipe
{
	int		fd[2];
	int		io[3];
	t_cmd	*new;
	int		k;
	int		fd_io[2];
}			t_pipe;

char	*get_env(char *env, t_list **envl);
void	ft_echo(char **args, int fd);
void	ft_env(t_list *envl, char **args, int fd);
void	ft_export(t_list **envl, char **args, int fd);
void	ft_unset(t_list **envl, char **args);
int		ft_cd(t_list **envl, char **path);
int		ft_cd_print_error(char ***path, int ret);
void	ft_pwd(t_list *envl);
void	ft_inc_shlvl(t_list *envl);
int		ft_exec_cmd(t_list *envl, char **args, int fork);
int		ft_launch_exec(char **args, t_list **envl, int fork);
void	ft_exit(char **args, int fork);
int		ft_redirect(t_file *fil_lst, int fd[2], int option, t_list **env);
void	ft_fork_pipe(int *io, char **args, t_list **envl, int *pid);
void	ft_set_io(int *fd_io, int *io, int out);
int		ft_pipe(t_cmd *lst, t_list **envl);
int		ft_wait_loop(t_cmd	*cmds);
int		ft_red_smpl_cmd(t_cmd *cmds, t_list **envl);
void	ft_launch_execution(t_cmd *cmds, t_list	**envl);
int		ft_red_smpl_cmd(t_cmd *cmds, t_list **envl);
void	ft_pipe_help(int fd[2], int io[3], int *k);
void	ft_initialize(int io[3], t_cmd	**new, t_cmd *lst, int *k);
void	ft_exit_child(void);
void	reset_stds(void);
void	set_pwd_oldpwd(t_list *envl, char *pwd_old);
void	ft_check_cd_home(char **path, t_list *envl);
int		ft_check_cd_void(char ***path, t_list *home);
void	ft_close(int fd);
void	ft_rd_print_error(char *path, int option);
void	ft_free_envv(t_list **env, t_envv **envv);
void	reset_stds(void);
void	ft_exec_wait(t_exec_hlp *var);
int		ft_pipe_last_cmd(t_pipe var, t_cmd *lst, t_list **envl);
void	handler(int c);
void	handler_2(int c);
void	handler_3(int c);
void	ft_her_doc_help(t_file *lst, t_list **env);
void	child_handler(int sig);
int		ft_check_path(char **path, char **args, t_list *envl);

t_global	g_help;

#endif
