#include "../../inc/minishell.h"\

int	cd_builtin(t_minishell *data)
{
	opendir(data->cmd[1]);
	if (data->cmd[1])
	{
		if (access(data->cmd[1], F_OK) != -1)
		{
			if (chdir(data->cmd[1]) == -1)
			{
				ft_putstr_fd("minishell: cd: ", 2);
				ft_putstr_fd(data->cmd[1], 2);
				ft_putstr_fd(":  Not a directory\n", 2);
				// if (ft_isvariable(data, "PWD") == 1)
				// {
				// 	// getcwd();
				// 	// export_builtin()
				// }
			}
		}
		else
		{
			ft_putstr_fd("minishell: cd: ", 2);
			ft_putstr_fd(data->cmd[1], 2);
			ft_putstr_fd(": No such file or directory\n", 2);
		}
		
	}
	return (1);
}

// if (opendir)
		// if (chdir(data->cmd[1]) != -1)
		// // {
		// // 	if (ft_isvariable(data, "PWD") == 1)
		// // 	{
		// // 		// printf("HOLA");
		// // 	}
		// }