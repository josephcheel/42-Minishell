#include "../inc/libft.h"

char	*ft_substr_free(char const *s, unsigned int start,
		size_t len, int one_if_free_s)
{
	size_t	s_len;
	size_t	size;
	char	*str;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (malloc(sizeof(char)));
	if (start + len > s_len)
		len = s_len - start;
	size = len + 1;
	str = (char *) malloc(size * sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s + start, len);
	str[len] = '\0';
	if (one_if_free_s == 1)
		free((void *)s);
	return (str);
}