void ft_command(char **cmd, char **envp)
{
	int i = -1, begin = 0, nproc = 0;

	while(cmd[++i])
	{
		if(!strcmp(cmd[i], "|") || cmd[i + 1] == NULL)
		{
			haspipe = 0;
			if(!strcmp(cmd[i], "|"))
			{
				haspipe = 1;
				cmd[i] = NULL;
			}
			ft_exec(cmd + begin, envp);
			begin = i + 1;
			nproc++;
		}
	}
	while(nproc-- > 0)
		waitpid(-1, 0, 0);
}

void ft_restorerd(void)
{
	int tmp;
	tmp = dup(STDIN_FILENO);
	if(dup2(dup_stdin, STDIN_FILENO) == -1)
		ft_fatalerr();
}
