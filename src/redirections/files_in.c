/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:39:58 by ageiser           #+#    #+#             */
/*   Updated: 2023/11/16 19:40:00 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_permission_files_in(t_list **head)
{
	t_list	*temp;

	temp = *head;
	while (temp)
	{
		if (access(temp->content, F_OK) == 0)
		{
			if (access(temp->content, W_OK) != 0)
			{
				ft_putstr_fd("minishell: ", 2);
				ft_putstr_fd(temp->content, 2);
				ft_putstr_fd(": Permission denied\n", 2);
				return (1);
			}
		}
		else
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(temp->content, 2);
			ft_putstr_fd(": No such file or directory\n", 2);
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}
