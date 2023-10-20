/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 03:00:04 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/20 12:55:21 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	ft_export_error_invalid_option(char *option)
{
	ft_putstr_fd("minishell: export: ", 2);
	ft_putstr_fd(option, 2);
	ft_putstr_fd(": invalid option\n", 2);
	ft_putstr_fd("export: usage: export [-nf]", 2);
	ft_putstr_fd("[name[=value] ...] or export -p\n", 2);
	g_status.status = 2;
}

static void	ft_export_error_not_valid_id(char *arg)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	g_status.status = 1;
}

int	ft_export(t_minishell *data, char **cmd)
{
	int		i;
	char	**variable;

	i = ft_cmdsize(cmd) - 1;
	if (i >= 1)
	{
		ft_export_error_invalid_option(cmd[1]);
		return (1);
	}
	while (cmd[++i])
	{
		if (ft_strchr(cmd[i], '='))
		{	
			variable = ft_split_env(cmd[i]);
			if (ft_check_var_rules(variable[0]))
				ft_set_variable(&data->lstenv, variable[0], variable[1]);
			else
				ft_export_error_not_valid_id(cmd[i]);
		}
		else
			if (!ft_check_var_rules(cmd[i]))
				ft_export_error_not_valid_id(cmd[i]);
	}
	data->env = ft_env_to_array(data->lstenv);
	return (1);
}
