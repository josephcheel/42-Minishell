/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:31:46 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/04 17:31:47 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/environment.h"

void	ft_free_env(t_env *head)
{
	t_env	*temporary;

	temporary = head;
	while (temporary != NULL)
	{
		if (temporary->id)
			free(temporary->id);
		if (temporary->value)
			free(temporary->value);
		temporary = temporary->next;
	}
}
