/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 03:00:04 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/22 14:33:11 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	ft_export_error_invalid_option(char *option, t_minishell *data)
{
	ft_putstr_fd("minishell: export: ", 2);
	ft_putstr_fd(option, 2);
	ft_putstr_fd(": invalid option\n", 2);
	ft_putstr_fd("export: usage: export [-nf]", 2);
	ft_putstr_fd("[name[=value] ...] or export -p\n", 2);
	data->status = 2;
}

static void	ft_export_error_not_valid_id(char *arg, t_minishell *data)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	data->status = 1;
}

static void	ft_declare_export(t_env *lstenv, t_minishell *data)
{
	t_env	*temp;

	temp = lstenv;
	while (temp)
	{
		printf("declare -x ");
		printf("%s", temp->id);
		printf("=");
		printf("\"%s\"\n", temp->value);
		temp = temp->next;
	}
	data->status = 0;
}

static int	ft_check_cases(char **cmd, int cmdsize,
	t_env *lstenv, t_minishell *data)
{
	if (cmdsize == 1 && ft_array_size(cmd) == 1)
	{
		ft_declare_export(lstenv, data);
		return (0);
	}
	else if (cmdsize == 2 && cmd[1][0] == '-')
	{
		ft_export_error_invalid_option(cmd[1], data);
		return (0);
	}
	return (1);
}

int	ft_export(t_minishell *data, char **cmd)
{
	int		i;
	char	**variable;

	i = ft_cmdsize(cmd) - 1;
	if (!ft_check_cases(cmd, i, data->lstenv, data))
		return (1);
	while (cmd[++i])
	{
		if (ft_strchr(cmd[i], '='))
		{
			variable = ft_split_env(cmd[i]);
			if (ft_check_var_rules(variable[0]))
				ft_set_variable(data->lstenv, variable[0],
					variable[1]);
			else
				ft_export_error_not_valid_id(cmd[i], data);
			ft_array_free(variable, ft_array_size(variable));
		}
		else
			if (!ft_check_var_rules(cmd[i]))
				ft_export_error_not_valid_id(cmd[i], data);
	}
	ft_array_free(data->env, ft_array_size(data->env));
	data->env = ft_env_to_array(data->lstenv);
	return (1);
}
