/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_quotes_values.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 02:38:04 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/22 21:33:58 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/split_quotes.h"

void	ft_get_quotes_values(char c, t_quote *quotes)
{
	if (c == '\"' && !quotes->simple)
		quotes->dbl++;
	if (c == '\'' && !quotes->dbl)
		quotes->simple++;
	if (c == '\"' && quotes->dbl == 2)
		quotes->dbl = 0;
	if (c == '\'' && quotes->simple == 2)
		quotes->simple = 0;
}
