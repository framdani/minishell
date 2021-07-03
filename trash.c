int	ft_pipe(t_cmd *lst, t_list **envl)
{
	int		fd[2];
	int		io[3];
	t_cmd	*new;
	int		k;
	int		fd_io[2];

	ft_initialize(io, &new, &lst, &k);
	while (lst->next)
	{
		pipe(fd);
		io[2] = fd[0];
		ft_redirect(lst->file, &fd_io[0], &fd_io[1], 1, envl);
		ft_set_io(fd_io, io, fd[1]);
		ft_fork_pipe(io, lst->args, envl, &lst->pid);
		ft_pipe_help(fd, io, &k);
		lst = lst->next;
	}
	ft_redirect(lst->file, &fd_io[0], &fd_io[1], 0, envl);
	ft_set_io(fd_io, io, 1);
	ft_fork_pipe(io, lst->args, envl, &lst->pid);
	if (k)
		close(fd[0]);
	return (ft_wait_loop(new));
}
