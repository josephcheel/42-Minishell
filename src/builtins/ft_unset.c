#include "../../inc/minishell.h"

void	ft_unset_node(t_env **lstenv, char *id)
{
	t_env *prev;
	t_env *node;

	prev = *lstenv;
	node = ft_find_id(*lstenv, id);
	if (!node)
		return ;
	while (prev)
	{
		if (prev == node)
		{
			*lstenv = node->next;
			free(prev->id);
			free(prev->value);
			free(prev);
			break ;
		}
		else if (prev->next == node)
		{
			prev->next = node->next;
			free(node->id);
			free(node->value);
			free(node);
			break ;
		}
		prev = prev->next;
	}
}

int	ft_unset(t_minishell *data, char **cmd)
{
	int i;

	i = ft_cmdsize(cmd);
	if (i >= 2)
	{
		ft_putstr_fd("minishell: unset: ", 2);
		ft_putstr_fd(cmd[1], 2);
		ft_putstr_fd(": invalid option\n", 2);
		ft_putstr_fd("unset: usage: unset [-f] [-v] [name ...]\n", 2);
		return (1);
	}
	while (cmd[i])
	{
		if (ft_check_var_rules(cmd[i]))
			ft_unset_node(&data->lstenv, cmd[i]);
		else
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(cmd[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
		}	
		i++;
	}
	return (1);
}
