/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 03:39:12 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/02 22:45:36 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	init_env(t_minishell *data, char **env)
{
	int		i;
	int		count;
	char	**split;
	t_env	*temp;

	i = 0;
	count = ft_array_size(env);
	data->lstenv = NULL;
	data->env = env;
	while (i < count)
	{
		split = ft_split_env(env[i]);
		temp = ft_create_new_node(split[0], split[1]);
		free(split);
		ft_insert_at_end(&data->lstenv, temp);
		i++;
	}
	return (0);
}
