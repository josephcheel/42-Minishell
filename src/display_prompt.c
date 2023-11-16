/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:28:06 by ageiser           #+#    #+#             */
/*   Updated: 2023/11/16 19:28:19 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*display_prompt_msg(void)
{
	char	*line;

	line = readline("42-Minishell ~ % ");
	if (ft_strlen(line) > 0)
		add_history(line);
	return (line);
}
