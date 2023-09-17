#ifndef SPLIT_QUOTES_H
# define SPLIT_QUOTES_H

// typedef struct s_split
// {
// 	int	quotes;
// 	int	open_quote;	
// 	int	nbr_words;
// 	char **split;
// }t_split;

int		ft_has_valid_quotes(char *str);

int		ft_count_words(char *str, int words);
int		isnotquote(char *str, int i, int type);
char	**alloc_split(char **split, char *str, int x);
int		split_len(char *str);
#endif 