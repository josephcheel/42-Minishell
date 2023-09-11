# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/15 11:26:03 by ageiser           #+#    #+#              #
#    Updated: 2022/10/10 14:20:43 by ageiser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#on pourra creer la <cible> :si les <dependences> sont satisfaites
#et depuis les dependances pour faire cette transformtion on tape la <commande>

#nom de sortie:
NAME = libft.a

#nom des fichiers a compiler:
SRC =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  	 ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
		ft_strlcat.c ft_toupper.c ft_tolower.c ft_strrchr.c \
  		ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strtrim.c \
		ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strlen.c \
		ft_strchr.c  ft_strjoin.c get_next_line.c get_next_line_utils.c \
		ft_putstr.c

#Flags de compilation
CFLAGS = -Wall -Wextra -Werror

#Shell d'effacement
RM = rm -f

#compilateur
CC = gcc

# cree et maintient les archives de la bibliotheques (man ar
# r = insere les fichiers membres dans l-archive
# c cree l'archive
# s ecrit un objet a l'index des fichiers
LIB = ar -rcs

#include le fichier libft.h
INCLUDE = libft.h

#les obj seront les sources en .c qui deviendront des .o
OBJ = $(SRC:.c=.o)

#nom des fichiers bonus a compiler
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

#les bonus obj seront les sources en .c qui deviendront des .o pour les bonus
BONUS_OBJ = $(BONUS:.c=.o)

#commande principale
all : $(NAME)

#commande lors de NAME
# $@ = nom cible
# $? = liste des dependances plus recentes que la cible
$(NAME): $(OBJ) $(INCLUDE)
	$(LIB) $@ $?

#transformation des .c en .o 
#gcc -Wall... (-c (cible) $< nom de la premiere dependence, donc .c) (-o (outuput))($@ nom cible)
%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

#commande effacement des .o:
clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

#commande effacement des .o et du NAME

fclean: clean
	$(RM) $(NAME)

# commande principale + fclean
re: fclean all

#commande principale des bonus
#@touch permet de modifier libtf.a et ainsi regenerer un libft.a lors de la
#compilation
bonus: $(OBJ) $(BONUS_OBJ) $(INCLUDE)
		$(LIB) $(NAME) $(OBJ) $(BONUS_OBJ) 
		@touch $@


#.PHONY indique ce qui ne creera pas un fichier et regarde si il existe deja
.PHONY: clean fclean all re
