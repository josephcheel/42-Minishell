/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:36:11 by ageiser           #+#    #+#             */
/*   Updated: 2023/11/22 00:02:06 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_write_syntax_error(char *raw_command, int i)
{
	if (raw_command[i + 1] == '|')
	{
		ft_putstr_fd("minishell: syntax error", 2);
		ft_putstr_fd("near unexpected token `|'\n", 2);
	}
}

char	*ft_first_step(t_env *lstenv, char *command, char *line)
{
	t_env	*envtemp;

	envtemp = NULL;
	if (!ft_isstralnum(command))
		return (NULL);
	if (ft_isvariable(lstenv, "PATH"))
	{
		envtemp = ft_find_id(lstenv, "PATH");
		line = envtemp->value;
		return (line);
	}
	else
		return (NULL);
}
