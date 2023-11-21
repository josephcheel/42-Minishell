/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quotes.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:59:19 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/20 20:26:26 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_QUOTES_H
# define SPLIT_QUOTES_H

# include "../../libft/inc/libft.h"

typedef struct s_quote{
	int	dbl;
	int	simple;
	int	long_malloc;
}t_quote;

#endif 