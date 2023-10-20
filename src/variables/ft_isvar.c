/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:13:05 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/20 11:13:55 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// Check if a variable name(id) is on the env list 
int	ft_isvariable(t_env *head, char *id)
{
	t_env	*temp;

	temp = head;
	while (temp)
	{
		if (ft_strcmp(temp->id, id) == 0)
			return (1);
		temp = temp->next;
	}
	return (0);
}
