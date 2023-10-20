/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:14:00 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/20 01:54:05 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_env(t_env *lstenv)
{
	t_env	*temp;

	temp = lstenv;
	while (temp)
	{
		printf("%s", temp->id);
		printf("=");
		printf("%s\n", temp->value);
		temp = temp->next;
	}
	global_status.status = 0;
	return (1);
}
