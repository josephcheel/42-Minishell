/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:11:28 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/31 16:47:51 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	ft_pwd_error_msg(char *arg, char *msg)
{
	ft_putstr_fd("minishell: pwd: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(msg, 2);
	return (0);
}

static int	ft_pwd_errors(char **cmd, t_minishell *data)
{
	data->status = 1;
	if (ft_isstrupper(cmd[0]) && ft_array_size(cmd) > 1)
	{
		if (ft_strlen(cmd[1]) >= 1)
		{
			ft_putstr_fd("PWD: illegal option -- -", 2);
			ft_putchar_fd(cmd[1][1], 2);
			ft_putstr_fd("\n", 2);
			ft_putstr_fd("pwd: usage: pwd [-L | -P]\n", 2);
		}
		return (1);
	}
	else if (ft_array_size(cmd) > 1 && ft_cmdsize(cmd) >= 2)
	{
		ft_pwd_error_msg(&cmd[1][1], ": invalid option\n");
		ft_putstr_fd("pwd: usage: pwd [-LP]\n", 1);
		return (1);
	}
	return (0);
}

int	ft_pwd(char **cmd, t_minishell *data)
{
	char	*path;

	if (ft_pwd_errors(cmd, data))
		return (1);
	path = (char *)malloc(sizeof(char) * 4097);
	getcwd(path, 4097);
	printf("%s\n", path);
	free(path);
	data->status = 0;
	return (1);
}
