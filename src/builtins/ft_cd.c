/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:14:54 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/19 18:21:12 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_cd_error_msg(char *arg, char *msg)
{
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(msg, 2);
	return (0);
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

void	ft_set_pwd(t_env **lstenv)
{
	char	*path;

	path = (char *)malloc(sizeof(char) * 200);
	getcwd(path, 200);
	ft_set_variable(lstenv, "PWD", path);
}

void	ft_set_oldpwd(t_env **lstenv)
{
	char	*path;

	path = (char *)malloc(sizeof(char) * 200);
	getcwd(path, 200);
	ft_set_variable(lstenv, "OLDPWD", path);
}

void	ft_chdir(t_minishell *data, char *dir)
{
	ft_set_oldpwd(&data->lstenv);
	if (ft_is_mode_permission_ok(dir))
	{
		if (chdir(dir) == 0)
			ft_set_pwd(&data->lstenv);
		else
			perror("chdir");
	}
}

void	ft_change_home(t_minishell *data)
{
	char	*value;

	if (ft_isvariable(data->lstenv, "HOME"))
	{
		value = ft_get_variable(&data->lstenv, "HOME");
		ft_chdir(data, value);
	}
	else
		ft_cd_error_msg("", "HOME not set\n");
}

void	ft_change_oldpwd(t_minishell *data)
{
	char	*value;

	if (ft_isvariable(data->lstenv, "OLDPWD"))
	{
		value = ft_get_variable(&data->lstenv, "OLDPWD");
		printf("%s\n", value);
		ft_chdir(data, value);
	}
	else
		ft_cd_error_msg("", "OLDPWD not set\n");
}

int	ft_cd_flags(t_minishell *data, char *flag)
{
	if (ft_strcmp(flag, "-") == 0)
	{
		ft_change_oldpwd(data);
		return (1);
	}
	else if (ft_strcmp(flag, "~") == 0)
	{
		ft_change_home(data);
		return (1);
	}
	return (0);
}

int	ft_cd(t_minishell *data, char **cmd)
{
	if (!cmd[1])
		ft_change_home(data);
	else if (cmd[1])
	{
		if (ft_strlen(cmd[1]) == 0)
			return (1);
		if (ft_cd_flags(data, cmd[1]))
			return (1);
		ft_chdir(data, cmd[1]);
	}
	return (1);
}
