#include "../includes/minishell.h"

void	ft_launch_execution(t_cmd *cmds, t_list	**envl)
{
	int		ret;

	if (!cmds->next)
		ret = ft_red_smpl_cmd(cmds, envl);
	else
		ret = ft_pipe(cmds, envl);
	unlink("/tmp/file");
	printf("ret = %d\n\n\n", ret);
}

int	ft_is_builtin(char *args)
{
	if (!ft_strncmp("echo", args, 5))
		return (1);
	else if (!ft_strncmp("env", args, 4))
		return (1);
	else if (!ft_strncmp("export", args, 7))
		return (1);
	else if (!ft_strncmp("unset", args, 6))
		return (1);
	else if (!ft_strncmp("cd", args, 3))
		return (1);
	else if (!ft_strncmp("pwd", args, 4))
		return (1);
	return (0);
}

int	ft_launch_exec(char **args, t_list **envl, int fork)
{
	int	ret;

	ret = 0;
	if (!ft_strncmp("echo", *args, 5))
		ft_echo(args + 1, 1);
	else if (!ft_strncmp("env", *args, 4))
		ft_env(*envl, 1);
	else if (!ft_strncmp("export", *args, 7))
		ft_export(envl, args + 1, 1);
	else if (!ft_strncmp("unset", *args, 6))
		ft_unset(envl, args + 1);
	else if (!ft_strncmp("cd", *args, 3))
		ft_cd(envl, args + 1);
	else if (!ft_strncmp("pwd", *args, 4))
		ft_pwd(*envl);
	else if (!ft_strncmp("exit", *args, 5))
		ft_exit(args + 1);
	else
		ret = ft_exec_cmd(*envl, args, fork);
	if (!fork && ft_is_builtin(*args))
		exit(0);
	return (ret);
}

void	ft_dup_io(int fd[2])
{
	if (fd[0] != -18)
		dup2(fd[0], STDIN_FILENO);
	if (fd[1] != -18)
		dup2(fd[1], STDOUT_FILENO);
	if (fd[0] != 0)
		close(fd[0]);
	if (fd[1] != 1)
		close(fd[1]);
}

int	ft_red_smpl_cmd(t_cmd *cmds, t_list **envl)
{
	int	fd[2];
	int	ret;

	if (!cmds->file)
	{
		ret = ft_launch_exec(cmds->args, envl, 1);
		return (ret);
	}
	else if (ft_redirect(cmds->file, fd, 0, envl) == 1)
	{
		if (cmds->args[0] == NULL)
		{
			close(fd[0]);
			close(fd[1]);
			return (0);
		}
		ft_dup_io(fd);
		ret = ft_launch_exec(cmds->args, envl, 1);
		reset_stds();
		return (ret);
	}
	return (1);
}
