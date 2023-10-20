/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 03:39:09 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/20 03:43:12 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/environment.h"

char	**ft_env_to_array(t_env *head)
{
	int		i;
	int		strsize;
	int		lstsize;
	char	**array;
	t_env	*temp;

	i = 0;
	lstsize = ft_listsize(head);
	array = malloc(sizeof(char *) * lstsize + 1);
	temp = head;
	while (i < lstsize)
	{
		strsize = ft_strlen(temp->id) + 1 + ft_strlen(temp->value);
		array[i] = malloc(sizeof(char) * strsize + 1);
		ft_strlcpy(array[i], temp->id, strsize + 1);
		ft_strlcat(array[i], "=", strsize + 1);
		ft_strlcat(array[i], temp->value, strsize + 1);
		temp = temp->next;
		i++;
	}
	array[i] = NULL;
	return (array);
}
