#include "../includes/minishell.h"

void	ft_launch_execution(t_cmd *cmds, t_list	*envl)
{
	int		ret;

	printf("\n\n\n");
	if (!cmds->next)
		ret = ft_red_smpl_cmd(cmds, envl);
	else
		ret = ft_pipe(cmds, envl);
	unlink("/tmp/file");
	printf("ret = %d\n\n\n", ret);
}

int	ft_launch_exec(char **args, t_list *envl, int fork)
{
	int	ret;

	ret = 0;
	if (!ft_strncmp("echo", *args, 5))
	{
		ft_echo(args + 1, 1);
		if (!fork)
			exit(0);
	}
	else if (!ft_strncmp("env", *args, 4))
	{
		ft_env(envl, 1);
		if (!fork)
			exit(0);
	}
	else if (!ft_strncmp("export", *args, 7))
	{
		ft_export(&envl, args + 1, 1);
		if (!fork)
			exit(0);
	}
	else if (!ft_strncmp("unset", *args, 6))
	{
		ft_unset(&envl, args + 1);
		if (!fork)
			exit(0);
	}
	else if (!ft_strncmp("cd", *args, 3))
	{
		ft_cd(envl, args + 1);
		if (!fork)
			exit(0);
	}
	else if (!ft_strncmp("pwd", *args, 4))
	{
		ft_pwd(envl);
		if (!fork)
			exit(0);
	}
	else if (!ft_strncmp("exit", *args, 5))
		ft_exit(args + 1);
	else
		ret = ft_exec_cmd(envl, args, fork);
	return (ret);
}

int	ft_red_smpl_cmd(t_cmd *cmds, t_list *envl)
{
	int fd[2];
	int	ret;

	if (!cmds->file)
	{
		ret = ft_launch_exec(cmds->args, envl, 1);
		return(ret);
	}
		// return (ft_launch_exec(cmds->args, envl, 1));
	else if(ft_redirect(cmds->file, &fd[0], &fd[1], 0, &envl) == 1)
	{
		if (cmds->args[0] == NULL)
		{
			close(fd[0]);
			close(fd[1]);
			return (0);
		}
		if (fd[0] != -18)
			dup2(fd[0], STDIN_FILENO);
		if (fd[1] != -18)
			dup2(fd[1], STDOUT_FILENO);
		if (fd[0] != 0)
			close(fd[0]);
		if (fd[1] != 1)
			close(fd[1]);
		ret = ft_launch_exec(cmds->args, envl, 1);
		
		reset_stds();
		return (ret);
	}
	// This means that it was a prob opening the file!
	return (1);
}
