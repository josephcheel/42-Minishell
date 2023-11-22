/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_multiple.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:54:16 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/22 14:30:40 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	exec_generic_multiple(t_minishell *data, char **splitted_cmd)
{
	char	*path;

	if (!ft_isstralnum(splitted_cmd[0]))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(splitted_cmd[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		exit (127);
	}
	path = find_command_route_env(data->lstenv, splitted_cmd[0]);
	if (!path)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(splitted_cmd[0], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		exit(1);
	}
	if (ft_redirect(data))
		exit (1);
	execve(path, splitted_cmd, data->env);
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(splitted_cmd[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	exit (127);
}

void	exec_multiple(t_minishell *data, char *raw_cmd)
{
	int		builtin;
	char	*cleaned_cmd;
	char	**splitted_cmd;

	ft_get_redit_value(raw_cmd, data);
	cleaned_cmd = ft_clean_redir_cmd(raw_cmd);
	splitted_cmd = ft_split_quotes(cleaned_cmd);
	builtin = is_builtin(splitted_cmd);
	if (builtin)
	{
		if (ft_redirect(data))
			exit (1);
		exec_builtin(data, splitted_cmd, 1, builtin);
		exit (0);
	}
	else if (!raw_cmd[0])
		exit(0);
	else
		exec_generic_multiple(data, splitted_cmd);
}
