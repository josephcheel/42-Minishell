/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:23:54 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/21 19:23:56 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	ft_check_pipe(char **separate_cmds, int i, int len)
{
	if (ft_isstralnum(separate_cmds[i]) == 0 && \
		(separate_cmds[len - 1] == separate_cmds[i]))
	{
		ft_putstr_fd("pipe>\n", 2);
		ft_array_free(separate_cmds, len);
		return (1);
	}
	else if (ft_isstralnum(separate_cmds[i]) == 0 \
		|| (ft_isstralnum(separate_cmds[i]) == 0
			&& separate_cmds[0] == separate_cmds[i]))
	{
		ft_array_free(separate_cmds, len);
		ft_putstr_fd(
			"minishell: syntax error near unexpected token `|'\n", 2);
		return (1);
	}
	return (0);
}

char	**ft_separate_cmds(t_minishell *data)
{
	int		i;
	int		len;
	char	**separate_cmds;

	i = -1;
	separate_cmds = ft_split_pipe(data->raw_cmd, '|');
	len = ft_array_size(separate_cmds);
	while (separate_cmds[++i])
		if (ft_check_pipe(separate_cmds, i, len))
			return (NULL);
	return (separate_cmds);
}
