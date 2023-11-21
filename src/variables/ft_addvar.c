/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addvar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:14:17 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/21 01:32:56 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

//Adds variable to list
void	ft_add_variable(t_env **head, char *id, char *value)
{
	t_env	*temp;
	t_env	*new_node;

	new_node = ft_create_new_node(id, value);
	if (!new_node)
		return ;
	temp = *head;
	if (!temp)
		*head = new_node;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
}
