/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:13:35 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/20 11:14:09 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_get_variable(t_env **head, char *id)
{
	t_env	*temp;

	if (ft_isvariable(*head, id))
	{
		temp = ft_find_id(*head, id);
		return (temp->value);
	}
	else
		return (NULL);
}
