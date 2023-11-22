/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quotes.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:59:19 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/22 21:47:44 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_QUOTES_H
# define SPLIT_QUOTES_H

# include "../../libft/inc/libft.h"

typedef struct s_quote{
	int	dbl;
	int	simple;
}t_quote;

void	ft_get_quotes_values(char c, t_quote *quotes);

int		ft_count_words(char *str);
int		ft_get_final_quote(char *str, int i, t_quote *quotes);
char	*ft_substr_split_quotes(char *str, int i, int start, int j);

#endif