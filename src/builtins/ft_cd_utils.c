/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 02:45:10 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/20 20:35:44 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_cd_error_msg(char *arg, char *msg, t_minishell *data)
{
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(msg, 2);
	data->status = 1;
	return (0);
}

void	ft_set_directory(t_env **lstenv, char *variable)
{
	char	*path;

	path = (char *)malloc(sizeof(char) * 4097);
	getcwd(path, 4097);
	ft_set_variable(lstenv, variable, path);
	if (path)
		free(path);
}

int	ft_cd_error_file_too_long(char *file, t_minishell *data)
{
	char	*filename;

	filename = ft_strrchr(file, '/');
	if (filename)
	{
		if (ft_strlen(filename) > 255)
		{
			ft_cd_error_msg(file, ": File name too long\n", data);
			return (1);
		}
	}
	else
	{
		if (ft_strlen(file) > 255)
		{
			ft_cd_error_msg(file, ": File name too long\n", data);
			return (1);
		}
	}
	return (0);
}

static int	ft_file_permissions(char *file, t_minishell *data)
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
					return (ft_cd_error_msg(file, ": File name too long\n", data));
				ft_cd_error_msg(file, ": Not a directory\n", data);
			}
		}
		else
			perror("stat");
	}
	else
		ft_cd_error_msg(file, ": Permission denied\n", data);
	return (0);
}

int	ft_is_mode_permission_ok(char *file, t_minishell *data)
{
	if (access(file, F_OK) != -1)
	{
		if (ft_file_permissions(file, data))
			return (1);
	}
	else
	{
		if (ft_cd_error_file_too_long(file, data))
			return (0);
		ft_cd_error_msg(file, ": No such file or directory\n", data);
	}
	return (0);
}
