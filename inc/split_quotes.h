/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quotes.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:59:19 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/20 13:00:16 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_QUOTES_H
# define SPLIT_QUOTES_H

int		ft_has_valid_quotes(char *str);

int		ft_count_words(char *str, int words);
int		isnotquote(char *str, int i, int type);
char	**alloc_split(char **split, char *str, int x);
int		split_len(char *str);

#endif 