/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quotes.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:59:19 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/21 04:07:09 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_QUOTES_H
# define SPLIT_QUOTES_H

# include "../../libft/inc/libft.h"

typedef struct s_quote{
	int	dbl;
	int	simple;
}t_quote;

t_quote	ft_get_quotes_values(char c, t_quote quotes);

#endif 