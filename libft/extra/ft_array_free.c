#include "../inc/libft.h"

char	**ft_array_free(char **Array, int i)
{
	while (i > 0)
		free(Array[--i]);
	free(Array);
	return (NULL);
}