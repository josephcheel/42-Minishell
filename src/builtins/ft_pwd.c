/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:11:28 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/20 02:46:19 by jcheel-n         ###   ########.fr       */
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

static int	ft_pwd_errors(char **cmd)
{
	global_status.status = 1;
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

int	ft_pwd(char **cmd)
{
	char	*path;

	if (ft_pwd_errors(cmd))
		return (1);
	path = (char *)malloc(sizeof(char) * 200);
	getcwd(path, 200);
	printf("%s\n", path);
	global_status.status = 0;
	return (1);
}
