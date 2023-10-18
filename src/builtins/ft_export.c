#include "../../inc/minishell.h"

int ft_export(t_minishell *data, char **cmd) //TODO: remove quote and spaces
{
	int	i;

	i = ft_cmdsize(cmd);
	if (i >= 2)
	{
		ft_putstr_fd("minishell: export: ", 2);
		ft_putstr_fd(cmd[1], 2);
		ft_putstr_fd(": invalid option\n", 2);
		ft_putstr_fd("export: usage: export [-f] [-v] [name ...]\n", 2);
		return (1);
	}
	while (cmd[i])
	{
		char **variable;

		if (ft_strchr(cmd[i], '='))
		{	
			variable = ft_split_env(cmd[i]);
			if (ft_check_var_rules(variable[0]))
				ft_set_variable(&data->lstenv, variable[0], variable[1]);
			else
			{
				ft_putstr_fd("minishell: export: `", 2);
				ft_putstr_fd(cmd[i], 2);
				ft_putstr_fd("': not a valid identifier\n", 2);
			}
		}
		else
		{
			if (!ft_check_var_rules(cmd[i]))
			{
				ft_putstr_fd("minishell: export: `", 2);
				ft_putstr_fd(cmd[i], 2);
				ft_putstr_fd("': not a valid identifier\n", 2);
			}
		}
		i++;
	}
	data->env = ft_env_to_array(data->lstenv);
	return (1);	
}
