/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:24:31 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/20 19:11:18 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_echo(char **cmd, int n_option, t_minishell *data)
{
	int	i;
	int	count;

	if (cmd[1])
	{
		count = ft_array_size(cmd);
		i = ft_cmdsize(cmd) - 1;
		while (++i < count - 1)
		{
			if (ft_strlen(cmd[i]))
				printf("%s", cmd[i]);
			printf(" ");
		}
		if (cmd[i])
			printf("%s", cmd[i]);
	}
	if (n_option == 0)
		printf("\n");
	data->status = 0;
	return (1);
}
