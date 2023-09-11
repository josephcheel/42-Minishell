/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:48:58 by ageiser           #+#    #+#             */
/*   Updated: 2022/10/06 16:11:02 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

//   STRMAPI
static char	funk(unsigned int i,char c)
	{
	i = 0;
	if ( c >= 65 && c <=90)
		c = c + 32;
		i++;
	return(c);
}
//     STRITERI  
static void	funk2(unsigned int i, char *c)
{
	i = 0;
	
	if ((int)c >= 65 && (int)c <= 90)
		c = c + 32;
		i++;
}	
// BONUS
void print_list (t_list *lst)
{
	if (lst)
{
	printf("[%s]\n",lst-> content);
}

}

int main (void)

{
//	int c = 'c';
//	int i = 0;
//	unsigned char c = 'a';
//	const char str[] = "+44";
//	char b[] = "";
//	char s[] = "turlucutu";
//	const char	s[]  = "Pleiades";
//	const char	s1[] = "Pleiades";
//	const char	s2[] = "abcdef";
//	char dst[] =       "         is my boat";
//	const char src[] = "Pleiades";
//	size_t len = 6;
//	size_t n = 3;
//	size_t dstsize = 29;
//	size_t count = 5;
//	size_t size = 20;
//	void *= NULL;
//	const char haystack[] = "Pleiades";
//	const char needle[] = "ia";
//	unsigned int start = 4;	
	printf("c = %c\n", c);	
	printf("isalpha %c = %d\n", c, ft_isalpha(c));
	printf("isdigit bool c = %d\n", ft_isdigit(c));
	printf("isalnum %d\n", ft_isalnum(c));
	printf("isascii %d\n", ft_isascii(c));
	printf("isprint %d\n", ft_isprint(c));
	printf("strlen %s\n", str);
	printf("strlen %d\n", ft_strlen(str));
	printf("memset c        = this is my project\n");
	printf("resultat %s\n", ft_memset(b, c, len));
	printf("memset c result = %s\n", b);
	printf("bzeros        =%s\n", s);
	printf("digit %zu\n", n);
	ft_bzero(s, n);
	printf("bzeros result = %s\n", s);
	printf("memcpy src: %s\n", src);
	printf("memcpy dst: %s\n", dst);
	ft_memcpy(dst, src, n);
	printf("memcpy dst: %s\n", dst);
	printf("memmove dst: %s\n", dst);
	printf("memmove src: %s\n", src);
	ft_memmove(dst, src, len);
	printf("memmove dst: %s\n", dst);
	printf("strlcpy src: %s\n", src);
	printf("strlcpy dst: %s\n", dst);
	printf("strlcpy :%zu\n", ft_strlcpy(dst, src, dstsize));
	printf("strlcpy dst: %s\n", dst);
	printf("strlcat src: %s\n", src);
	printf("strlcat dst: %s\n", dst);
	printf("strlcat :%zu\n", ft_strlcat(dst, src, dstsize));
	printf("strlcat dst: %s\n", dst);
	printf("toupper str : %c\n", c);
	ft_toupper(c);
	printf("result  str : %c\n", c);
	printf("tolower c : %c\n", c);
	printf("result c  : %c\n", ft_tolower(c));
	printf("strchr string lettre, %s %c\n", s, c);
	printf("resultat: %s\n", ft_strchr(s, c));
	printf("strrchr string lettre, %s %c\n", s, c);
	printf("resultat: %s\n", ft_strrchr(s, c));
	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("size_t: %zu\n", n);
	printf("strncmp: %d\n", ft_strncmp(s1, s2, n));
	printf("string %s\nlettre %c\nsize_t %zu\n", s, c, n);
	printf("memchr: %s\n", ft_memchr(s, c, n));
	printf("string1: %s\nstring2: %s\n", s1, s2);
	printf("memcmp: %d\n", ft_memcmp(s1, s2, n));
	printf("haystack: %s\nneedle: %s\nsize_t: %zu\n", haystack, needle, len);
	printf("strnstr : %s\n", ft_strnstr(haystack, needle, len));
	printf("str : %s\n", str);
	printf("atoi: %d\n", ft_atoi(str));

//   CALLOC
	int i;
	int *ptr;
	size_t count;
	size_t size;
	i = 0;
	count = 20;
	size = 1;
	printf("calloc count: %zu\nsize: %zu\n", count, size);
	ft_calloc(count, size);
	for(i = 0; (size_t)i < count; i++)	
	printf("[%d] ", *ptr);

//      STRDUP
	printf("origin %s\n", s1);
	printf("copied %s\n", ft_strdup(s1));

//      SUBSTR
	printf("origin %s\n", s);
	printf("copied %s\n", ft_substr(s, start, len));

//     	STRJOIN
	char const s1[] = "Pleiades";
	char const s2[] = " is my boat";
	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("strjoin: %s\n", ft_strjoin(s1, s2)); 	

//      STRTRIM	
	char const s1[] = "#Pleiades!";
	char const set[]  = "#!";
	printf("s1: %s\n", s1);
	printf("set: %s\n", set);
	printf("result: %s\n", ft_strtrim(s1, set));

//      SPLIT	
	char **array;
	char const s[] = "Pleiades is my boat";
	char c = ' ';
	int i = 0;
	printf("s: %s\nc: %c\n", s, c);
	array = ft_split(s, c);
	printf("result: %s\n", *ft_split(s, c)); 
	//retourne un pointeur sur le premier tableau
	while (i < 4)
	{
	printf("mot [%d] = %s\n", i, array[i]);
	i++;
	}

//    ITOA
	int n;
	n = -38938475;

	printf("n = %d\n", n);
	printf("itoa %s\n", ft_itoa(n));

//    STRMAPI
	char const s[] = "PLEIADES IS MY  BOAT";

	printf("s: %s\n", s);
	printf("s: %s\n", ft_strmapi(s, funk));

	return(0);
	}
//     STRITERI  

	char s[] = "PLEIADES IS MY BOAT";
	printf("s: %s\n", s);
	ft_striteri(s, funk2);
	printf("s: %s\n", s);
//     BONUS
	t_list *lst = NULL;

	lst = ft_lstnew("Hola");
	print_list(lst);

	ft_lstadd_front(&lst, ft_lstnew("Hello"));
	print_list(lst);

	printf("size %d\n", ft_lstsize(lst));
}
