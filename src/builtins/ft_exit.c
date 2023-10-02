#include "../../inc/minishell.h"

int ft_is_bigger_maxll(char *str)
{
	if (ft_strcmp(str, "-9223372036854775808") > 0)
		return (1);
	if (ft_strcmp(str, "9223372036854775807") > 0)
		return (1);
	return (0);
}

int	exit_builtin(t_minishell *data)
{
	long long	nbr;

	// ft_putstr_fd("exit\n", 2);
	// if (data->cmd[1]) 
	// 	data->cmd[1] = ft_strtrim(data->cmd[1], " ");
	if (data->cmd_and_arguments_size >= 2)
	{
		if (ft_isnumeric(data->cmd[1]) && data->cmd_and_arguments_size >= 3)
		{
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
			return (1);
		}
		else if (!ft_isnumeric(data->cmd[1]))
		{
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(data->cmd[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			exit(255);
		}
		else if (ft_isnumeric(data->cmd[1]))
		{
			nbr = ft_atoll(data->cmd[1]);
			if (!nbr)
				return (255);
			while (nbr > 256)
			{
				nbr -= 256;
			}
			exit(nbr);
		}
	}
	exit(EXIT_SUCCESS);
}