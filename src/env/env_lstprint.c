/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lstprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:18:52 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/04 22:44:51 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/environment.h"

void	ft_printlist_id(t_env *head, char *id)
{
	t_env *temporary;
	temporary = head;
	printf("%s: ", id);
	while(temporary != NULL)
	{
		printf("%s - ",temporary->id);
		temporary = temporary->next;
	}
	printf("\n");
}


void	ft_printlist_value(t_env *head, char *id)
{
	t_env *temporary;
	temporary = head;
	printf("%s: ", id);
	while(temporary != NULL)
	{
		printf("%s - ",temporary->value);
		temporary = temporary->next;
	}
	printf("\n");
}
