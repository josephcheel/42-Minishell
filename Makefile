#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#	 __  __    __    _  _  ____  ____  ____  __    ____ 		    	 	 #
#	(  \/  )  /__\  ( )/ )( ___)( ___)(_  _)(  )  ( ___)		   		     #
#	 )    (  /(__)\  )  (  )__)  )__)  _)(_  )(__  )__) 		     		 #
#	(_/\/\_)(__)(__)(_)\_)(____)(__)  (____)(____)(____) 𝕓𝕪 𝕁𝕠𝕤𝕖𝕡𝕙 ℂ𝕙𝕖𝕖𝕝       #									
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──NAME──✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

NAME		=	minishell

#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──CMD───✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

# include ../libft/Makefile

CC			=	gcc
RLFLAGS		= 	-lreadline 
CFLAGS		=	-Wall -Werror -Wextra
XFLAGS		= -fsanitize=address -g2 -g

AR			=	ar rcs
RM			=	rm -f
MD			=	mkdir -p
CP			=	cp -f

#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅DIRECTORIES✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

SRC_DIR			=	src/
BUILTINS_DIR	=	builtins/
ENV_DIR			=	env/
VAR_DIR			= 	variables/
EXEC_DIR		=	exec/
CMDS_DIR		= 	command/
TERM_DIR		=	termios/

OBJ_DIR			=	build/

INC_DIR			=	inc/
LIBFT_INC		= 	libft/inc/

LIBFT_DIR		= 	libft/
LIBFT			=	libft/libft.a

INCLUDE			+= -I $(INC_DIR) -I $(LIBFT_INC)

# Flags for Campus
LDFLAGS = /Users/${USER}/.brew/opt/readline/lib
RFLAGS = /Users/${USER}/.brew/opt/readline/include

# Flags for Home
# LDFLAGS	=/opt/homebrew/opt/readline/lib
# RFLAGS	= /opt/homebrew/opt/readline/include
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧─SORCES─✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

MS_SRCS			=	main.c display_prompt.c ft_split_quotes.c\
                    ft_has_valid_quotes.c  ft_signal_handler.c

BUILTINS	 	=	is_builtin.c ft_echo.c ft_pwd.c ft_cd.c  ft_env.c ft_export.c ft_unset.c ft_exit.c

ENV				=	set_env.c ft_split_env.c

EXEC			=	exec_one.c

CMDS 			=	commands.c command_utils.c one_command.c

SIG				=

TERM			= init_termios.c

#VARIABLES		= 	ft_replace_variable.c

SRCS			+=	$(addprefix $(SRC_DIR), $(MS_SRCS))
SRCS			+= 	$(addprefix $(SRC_DIR), $(addprefix $(BUILTINS_DIR), $(BUILTINS)))
SRCS			+= 	$(addprefix $(SRC_DIR), $(addprefix $(ENV_DIR), $(ENV)))
SRCS			+= 	$(addprefix $(SRC_DIR), $(addprefix $(EXEC_DIR), $(EXEC)))
SRCS			+= 	$(addprefix $(SRC_DIR), $(addprefix $(CMDS_DIR), $(CMDS)))
SRCS			+= 	$(addprefix $(SRC_DIR), $(addprefix $(TERM_DIR), $(TERM)))
#SRCS			+= 	$(addprefix $(SRC_DIR), $(addprefix $(VAR_DIR), $(VARIABLES)))



OBJS			=	$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
DEPS			+=	$(addsuffix .d, $(basename $(OBJS)))

#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#•❅──────✧❅✦❅✧──────❅••❅───OBJECT DEPENDENCY TARGET───❅••❅──────✧❅✦❅✧──────❅•#
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

$(OBJ_DIR)%.o : %.c Makefile 
	@$(MD) $(dir $@)
	@make -sC $(LIBFT_DIR)
	@echo "$(WARN_COLOR)Compiling: $<$(NO_COLOR)"
	@$(CC) -MT $@ -MMD -MP -c $(CFLAGS) -I$(RFLAGS) $(INCLUDE) $< -o $@ 

#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧─TARGET─✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

all:		libft_link $(NAME) 

$(NAME):	$(LIBFT) $(OBJS) 
			@$(CC) $(CFLAGS) $(RLFLAGS) -L$(LDFLAGS) $(XFLAGS) $(LIBFT) $(OBJS) -o $(NAME)
			@echo "$(OK_COLOR)$(NAME) Compiled!$(NO_COLOR)"

clean:
			@make clean -sC $(LIBFT_DIR)
			@$(RM) -r $(OBJ_DIR)
			@echo "$(ERROR_COLOR)Dependencies and objects removed$(NO_COLOR)"

fclean:		clean
			@make fclean -sC $(LIBFT_DIR)
			@$(RM) $(NAME) $(NAME_BONUS)
			@echo "$(ERROR_COLOR)Programs removed$(NO_COLOR)"

re:			fclean all

run:		all
			@echo ""
			@echo "$(OK_COLOR)Launching Minishell...$(NO_COLOR)"
			@echo ""
			@./minishell

libft_link:	
			@make -sC $(LIBFT_DIR)

-include $(DEPS)
-include $(DEPS_BONUS)

#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○IGNORE○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

.PHONY: all bonus clean fclean re run libft_link

#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧─COLOR──✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

NO_COLOR		=	\x1b[0m
OK_COLOR		=	\x1b[32;01m
ERROR_COLOR		=	\x1b[31;01m
WARN_COLOR		=	\x1b[33;01m

OK_STRING		=	$(OK_COLOR)[OK]$(NO_COLOR)
ERROR_STRING	=	$(ERROR_COLOR)[ERRORS]$(NO_COLOR)
WARN_STRING		=	$(WARN_COLOR)[WARNINGS]$(NO_COLOR)


