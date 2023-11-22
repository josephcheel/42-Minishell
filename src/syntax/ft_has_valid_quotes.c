/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_valid_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:35:15 by ageiser           #+#    #+#             */
/*   Updated: 2023/11/22 14:33:45 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_has_valid_quotes(char *str)
{
	int		i;
	t_quote	quotes;

	i = -1;
	quotes.simple = 0;
	quotes.dbl = 0;
	if (ft_strlen(str) == 0)
		return (1);
	while (str[++i])
	{
		if ((quotes.dbl % 2 == 0 || (quotes.dbl == 0 && quotes.simple != 0))
			&& (str[i] == '\''))
			quotes.simple++;
		else if ((quotes.simple % 2 == 0 || \
			(quotes.simple == 0 && quotes.dbl != 0))
			&& str[i] == '\"')
			quotes.dbl++;
	}
	if ((quotes.dbl % 2 == 0 && quotes.simple == 0)
		|| (quotes.simple % 2 == 0 && quotes.dbl == 0)
		|| (quotes.dbl % 2 == 0 && quotes.simple % 2 == 0))
		return (1);
	else
		return (0);
}
