/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:14:00 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/19 18:14:10 by jcheel-n         ###   ########.fr       */
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
	return (1);
}
