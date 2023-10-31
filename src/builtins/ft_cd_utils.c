/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 02:45:10 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/31 16:53:03 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_cd_error_msg(char *arg, char *msg)
{
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(msg, 2);
	g_status.status = 1;
	return (0);
}

void	ft_set_directory(t_env **lstenv, char *variable)
{
	char	*path;

	path = (char *)malloc(sizeof(char) * 4097);
	getcwd(path, 4097);
	ft_set_variable(lstenv, variable, path);
	free(path);
}

int	ft_cd_error_file_too_long(char *file)
{
	char	*filename;

	filename = ft_strrchr(file, '/');
	if (filename)
	{
		if (ft_strlen(filename) > 255)
		{
			ft_cd_error_msg(file, ": File name too long\n");
			return (1);
		}
	}
	else
	{
		if (ft_strlen(file) > 255)
		{
			ft_cd_error_msg(file, ": File name too long\n");
			return (1);
		}
	}
	return (0);
}

static int	ft_file_permissions(char *file)
{
	struct stat	buffer;

	if (access(file, R_OK) != -1 && access(file, X_OK) != -1)
	{
		if (stat(file, &buffer) == 0)
		{
			if (S_ISDIR(buffer.st_mode))
				return (1);
			else
			{
				if (ft_strlen(ft_strrchr(file, '/')) > 255)
					return (ft_cd_error_msg(file, ": File name too long\n"));
				ft_cd_error_msg(file, ": Not a directory\n");
			}
		}
		else
			perror("stat");
	}
	else
		ft_cd_error_msg(file, ": Permission denied\n");
	return (0);
}

int	ft_is_mode_permission_ok(char *file)
{
	if (access(file, F_OK) != -1)
	{
		if (ft_file_permissions(file))
			return (1);
	}
	else
	{
		if (ft_cd_error_file_too_long(file))
			return (0);
		ft_cd_error_msg(file, ": No such file or directory\n");
	}
	return (0);
}
