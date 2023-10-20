/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 02:45:10 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/20 03:17:12 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_cd_error_msg(char *arg, char *msg)
{
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(msg, 2);
	global_status.status = 1;
	return (0);
}

void	ft_set_directory(t_env **lstenv, char *variable)
{
	char	*path;

	path = (char *)malloc(sizeof(char) * 200);
	getcwd(path, 200);
	ft_set_variable(lstenv, variable, path);
}

int	ft_is_mode_permission_ok(char *file)
{
	struct stat	buffer;

	if (ft_strlen(file) > 255)
		return (ft_cd_error_msg(file, ": File name too long\n"));
	if (access(file, F_OK) != -1)
	{
		if (access(file, R_OK) != -1 && access(file, X_OK) != -1)
		{
			if (stat(file, &buffer) == 0)
			{
				if (S_ISDIR(buffer.st_mode))
					return (1);
				else
					ft_cd_error_msg(file, ": Not a directory\n");
			}
			else
				perror("stat");
		}
		else
			ft_cd_error_msg(file, ": Permission denied\n");
	}
	else
		ft_cd_error_msg(file, ": No such file or directory\n");
	return (0);
}
