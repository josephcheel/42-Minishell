/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_redir_syntax.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:04:38 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/22 23:10:43 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	ft_check_redir_ends(char *str)
{
	int	len;

	len = ft_strlen(str) - 1;
	if (str[len] == ' ')
	{
		while (str[len] == ' ')
			len--;
		if (str[len] == '<' || str[len] == '>')
		{
			write(2, "minishell: syntax error near unexpected token `newline'\n", 57);
			return (1);
		}
	}
	if (str[ft_strlen(str) - 1] == '<' || str[ft_strlen(str) - 1] == '>')
	{
			write(2, "minishell: syntax error near unexpected token `newline'\n", 57);
			return (1);
	}
	return (0);
}

int	ft_check_redir_sytax(char *str)
{
	int	i;
	int	redir_left;
	int	redir_right;
	t_quote	quotes;

	i = 0;
	quotes.dbl = 0;
	quotes.simple = 0;
	redir_left = 0;
	redir_right = 0;
	while (str[i])
	{
		ft_get_quotes_values(str[i], &quotes);
		if (str[i] == '<' && !quotes.dbl && !quotes.simple)
			redir_left++;
		else if (str[i] == '>' && !quotes.dbl && !quotes.simple)
			redir_right++;
		if (ft_isspace(str[i]) && !quotes.dbl && !quotes.simple)
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
	if (ft_check_redir_ends(str))
		return (1);
	return (0);
}
