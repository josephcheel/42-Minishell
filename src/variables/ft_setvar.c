/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setvar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:16:09 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/22 14:27:22 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// Adds or change the variable value with the id
void	ft_set_variable(t_env **head, char *id, char *value)
{
	char	**split;
	t_env	*temp;

	if (ft_isvariable(*head, id))
	{
		temp = ft_find_id(*head, id);
		if (temp->value)
			free(temp->value);
		split = ft_split_quotes(value);
		if (split[0])
			temp->value = ft_strdup(split[0]);
		ft_array_free(split, ft_array_size(split));
	}
	else
		ft_add_variable(head, id, value);
}
