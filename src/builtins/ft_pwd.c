/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:11:28 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/19 18:13:27 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_pwd(char **cmd)
{
	char	*path;

	if (ft_isstrupper(cmd[0]) && ft_array_size(cmd) > 1)
	{
		ft_putstr_fd("usage: pwd [-L | -P]\n", 2);
		return (1);
	}
	path = (char *)malloc(sizeof(char) * 200);
	getcwd(path, 200);
	printf("%s\n", path);
	return (1);
}
