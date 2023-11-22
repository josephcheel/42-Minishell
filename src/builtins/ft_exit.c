/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 03:31:25 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/07 01:06:59 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_is_bigger_maxll(char *str)
{
	int	negative;

	negative = 0;
	while (str[0] == '-' && str[1] == '-')
		str++;
	if (str[0] == '-')
		negative = 1;
	if (ft_strcmp(str, "-9223372036854775808") == 0)
		exit (0);
	else if (ft_strcmp(str, "9223372036854775807") == 0)
		exit (255);
	else if (ft_strcmp(str, "-9223372036854775808") > 0 && negative == 1)
		return (1);
	else if (ft_strcmp(str, "9223372036854775807") > 0)
		return (1);
	return (0);
}

// static void ft_exit_error_numeric_req();
// {
// }

int	ft_exit(char **cmd, int multiple_cmd, t_minishell *data)
{
	long long	nbr;

	if (!multiple_cmd)
		ft_putstr_fd("exit\n", 2);
	if (ft_array_size(cmd) >= 2)
	{
		if (ft_isnumeric(cmd[1]) && ft_array_size(cmd) >= 3)
		{
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
			return (1);
		}
		else if (!ft_isnumeric(cmd[1]))
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd("exit: ", 2);
			ft_putstr_fd(cmd[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			exit(255);
		}
		else if (ft_isnumeric(cmd[1]))
		{
			if (ft_is_bigger_maxll(cmd[1]) == 1)
			{
				ft_putstr_fd("minishell: ", 2);
				ft_putstr_fd("exit: ", 2);
				ft_putstr_fd(cmd[1], 2);
				ft_putstr_fd(": numeric argument required\n", 2);
				exit (255);
			}
			else
				nbr = ft_atoll(cmd[1]);
			if (nbr == 0)
				exit (0);
			while (nbr > 256)
				nbr = nbr - 256;
			ft_array_free(cmd, ft_array_size(cmd));
			exit(nbr);
		}
	}
	if (multiple_cmd)
	{
		data->status = 0;
		return (1);
	}
	exit(data->status);
}
