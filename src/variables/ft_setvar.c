/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setvar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:16:09 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/20 12:14:59 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// Adds or change the variable value with the id
void	ft_set_variable(t_env **head, char *id, char *value)
{
	t_env	*temp;

	if (ft_isvariable(*head, id))
	{
		temp = ft_find_id(*head, id);
		temp->value = value;
	}
	else
		ft_add_variable(head, id, value);
}
