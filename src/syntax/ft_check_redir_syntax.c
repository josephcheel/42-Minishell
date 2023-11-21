/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_redir_syntax.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:04:38 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/21 04:15:55 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_check_redir_sytax(char *str)
{
	int	i;
	int	len;
	int	redir_left;
	int	redir_right;

	i = 0;
	len = ft_strlen(str) - 1;
	redir_left = 0;
	redir_right = 0;
	while (str[i])
	{
		if (str[i] == '<' )
			redir_left++;
		else if (str[i] == '>')
			redir_right++;
		if (ft_isspace(str[i]))
		{
			redir_left = 0;
			redir_right = 0;
		}
		if ((redir_left > 2 && !redir_right) || \
		(redir_right > 2 && !redir_left))
			return (write(2, "minishell: syntax error near unexpected token `>'\n", 51));
		else if (redir_left && redir_right)
			return(write(2, "minishell: syntax error near unexpected token `>'\n", 51));
		i++;
	}
	if (str[len] == ' ')
	{
		while (str[len] == ' ')
			len--;
		if (str[len] == '<' || str[len] == '>')
			return (write(2, "minishell: syntax error near unexpected token `newline'\n", 57));
	}
	if (str[ft_strlen(str) - 1] == '<' || str[ft_strlen(str) - 1] == '>')
		return (write(2, "minishell: syntax error near unexpected token `newline'\n", 57));
	return (0);
}
