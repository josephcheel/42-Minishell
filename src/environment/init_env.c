/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 03:39:12 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/25 23:20:55 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	**ft_malloc_env_array(char **env)
{
	int		i;
	char	**array;

	i = -1;
	array = malloc(sizeof(char *) * (ft_array_size(env) + 1));
	while (env[++i])
		array[i] = ft_strdup(env[i]);
	array[i] = NULL;
	return (array);
}

int	init_env(t_minishell *data, char **env)
{
	int		i;
	int		count;
	char	**split;
	t_env	*temp;

	i = 0;
	count = ft_array_size(env);
	if (!count)
		return (write(2, "Init env Error\n", 16));
	data->lstenv = NULL;
	data->env = ft_malloc_env_array(env);
	if (!data->env)
		write(2, "Init env Error\n", 16);
	while (i < count)
	{
		split = ft_split_env(env[i]);
		temp = ft_envnew(split[0], split[1]);
		if (temp)
			ft_envadd_back(&data->lstenv, temp);
		ft_array_free(split, ft_array_size(split));
		i++;
	}
	return (0);
}
