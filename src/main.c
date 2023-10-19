/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:00:06 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/19 19:27:39 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	init_minishell(t_minishell *data, char **env)
{
	if (init_env(data, env))
		return (1);
	if (init_term(data))
		return (1);
	if (init_term_fd(data))
		return (1);
	data->status = 0;
	return (0);
}

int	finish_minishell(t_minishell *data)
{
	close_term_fd(data);
	restore_term(data);
	return (0);
}

int	ft_ctrl_d(void)
{
	if (isatty(STDIN_FILENO))
		write(2, "exit\n", 6);
	exit (EXIT_SUCCESS);
}

int	main(int ac, char **av, char **env)
{
	t_minishell	data;

	if (ac != 1 && !av)
		return (1);
	if (init_minishell(&data, env))
		;
	while (1)
	{
		signal(SIGINT, signal_handler);
		data.raw_cmd = display_prompt_msg();
		if (!data.raw_cmd)
			ft_ctrl_d();
		if (ft_strlen(data.raw_cmd) > 0 && ft_isstralnum(data.raw_cmd))
			ft_commands(&data);
		reset_term_fd(&data);
	}
	if (finish_minishell(&data))
		;
	return (0);
}
