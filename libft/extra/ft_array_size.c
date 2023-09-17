#include "../inc/libft.h"

int	ft_array_size(char **array)
{
	int count;
	char **ptr;
	
	count = 0;
	ptr = array;
   	while (*ptr != NULL)
	{
		count++;
		ptr++;
    }
	return (count);
}