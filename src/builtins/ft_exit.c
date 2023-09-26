#include "../../inc/minishell.h"

int	exit_builtin(t_minishell *data)
{
	long nbr;

	if (data->cmd_and_arguments_size >= 2)
	{
		if (ft_isnumeric(data->cmd[1]))
		{
			printf("ARG: %s\n", data->cmd[1]);
			ft_putstr_fd("exit\n", 2);
			nbr = ft_atol(data->cmd[1]);
			exit(nbr);
			return (-1);
		}
		else if (!ft_isnumeric(data->cmd[1]))
		{
			ft_putstr_fd("exit\n", 2);
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(data->cmd[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			exit(255);
		}
	}
	ft_putstr_fd("exit\n", 2);
	exit(EXIT_SUCCESS);
}