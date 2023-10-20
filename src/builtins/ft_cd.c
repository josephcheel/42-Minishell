/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:14:54 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/20 02:44:42 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	ft_chdir(t_minishell *data, char *dir)
{
	ft_set_directory(&data->lstenv, "OLDPWD");
	if (ft_is_mode_permission_ok(dir))
	{
		if (chdir(dir) == 0)
			ft_set_directory(&data->lstenv, "PWD");
		else
			perror("chdir");
	}
}

static void	ft_change_home(t_minishell *data)
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

static void	ft_change_oldpwd(t_minishell *data)
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

static int	ft_cd_flags(t_minishell *data, char *flag)
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
