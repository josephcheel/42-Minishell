/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quotes.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:59:19 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/18 20:42:32 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_QUOTES_H
# define SPLIT_QUOTES_H

#include "../../libft/inc/libft.h"

typedef struct s_quote{
	int dbl;
	int	simple;
	int long_malloc;
}t_quote;

int		ft_has_valid_quotes(char *str);

#endif 