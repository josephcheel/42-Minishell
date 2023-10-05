#include "../../inc/minishell.h"

int ft_is_bigger_maxll(char *str)
{
	int negative;

	negative = 0;
	while (str[0] == '-'  && str[1] == '-')
		str++;
	if (str[0] == '-')
		negative = 1;
	if  (ft_strcmp(str, "-9223372036854775808") == 0 )
		exit (0);
	else if (ft_strcmp(str, "9223372036854775807") == 0)
		exit (255);
	else if  (ft_strcmp(str, "-9223372036854775808") > 0 && negative == 1)
		return (1);
	else if (ft_strcmp(str, "9223372036854775807") > 0)
		return (1);
	return (0);
}

int	exit_builtin(t_minishell *data)
{
	long long	nbr;

	ft_putstr_fd("exit\n", 2);
	// if (data->cmd[1]) 
	// 	data->cmd[1] = ft_strtrim(data->cmd[1], " ");
	if (data->cmd_and_arguments_size >= 2)
	{
		if (ft_isnumeric(data->cmd[1]) && data->cmd_and_arguments_size >= 3)
		{
			// ft_putstr_fd("exit\n", 2);
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
			return (1);
		}
		else if (!ft_isnumeric(data->cmd[1]))
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd("exit: ", 2);
			ft_putstr_fd(data->cmd[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			exit(255);
		}
		else if (ft_isnumeric(data->cmd[1]))
		{
			if (ft_is_bigger_maxll(data->cmd[1]) == 1)
			{
				ft_putstr_fd("minishell: ", 2);
				ft_putstr_fd("exit: ", 2);
				ft_putstr_fd(data->cmd[1], 2);
				ft_putstr_fd(": numeric argument required\n", 2);
				exit (255);
			}
			else 
				nbr = ft_atoll(data->cmd[1]);
			// printf("NBR: %lld", nbr);
			if (nbr == 0)
				exit (0);
			while (nbr > 256)
				nbr = nbr - 256;
			exit(nbr);
		}
	}
	printf("STATUS 2 %d\n", data->status);
	exit(data->status);
}