#include "../../inc/minishell.h"

// void	close_init_redirs(t_master *master)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	if (master->std_in != -1)
// 		i = close(master->std_in);
// 	if (master->std_out != -1)
// 		j = close(master->std_out);
// 	if (i == -1 || j == -1)
// 	{
// 		free_master(master);
// 		exit(1);
// 	}
// }

void	exec_multiple(t_minishell *data, char *cmd)
{
	char	*path;
	char	**splitted_cmd;

	splitted_cmd = ft_split_quotes(cmd);
	if (is_builtin(data, splitted_cmd, 1))
		exit(0);
	else if (!cmd[0])
		exit(0);
	else
	{
		if (!ft_isstralnum(splitted_cmd[0]))
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(splitted_cmd[0], 2);
			ft_putstr_fd(": command not found\n", 2);
			exit (127);
		}
		path = find_command_route_env(data->lstenv, data->env, splitted_cmd[0]);
		if (!path)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(data->cmd[0], 2);
			ft_putstr_fd(": No such file or directory\n", 2);
			exit(1);
		}
		execve(path, splitted_cmd, data->env);
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(splitted_cmd[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		exit (127);
	}
}
