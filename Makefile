# Project file
NAME = minishell

# Project builds and dirs
SRCDIR = ./src/
SRCNAMES = $(shell ls $(SRCDIR) | grep -E ".+\.c") #list of files ending with .c in src dir
SRC = $(addprefix $(SRCDIR), $(SRCNAMES))
INC = ./inc/
BUILDDIR = ./build/ #temporary .o folder
BUILDOBJS = $(addprefix $(BUILDDIR), $(SRCNAMES:.c=.o))

# Libft builds and dirs
LIBDIR = ./libft/
LIBFT = ./libft/libft.a
LIBINC = ./libft/includes/ #simplify this part

PWD := $(shell pwd) #?
# userapp dir
ROOTDIR := $(PWD)/../../.. #?
RT_DIR=$(ROOTDIR)/sdk/rt-thread #? possibly multi threads working together

#?->compilation flag to simplify if possible
MYCFLAGS= -march=armv7-a -marm -msoft-float -Wall -g -gdwarf-2 -n --static -I. -I$(RT_DIR)/include -I$(RT_DIR)/components/dfs -I$(RT_DIR)/components/drivers -I$(RT_DIR)/components/finsh -I$(RT_DIR)/components/net
MYLDFLAGS= -T $(ROOTDIR)/linker_scripts/arm/cortex-a/link.lds -march=armv7-a -marm -msoft-float -L$(RT_DIR)/lib -Wl,--whole-archive -lrtthread -Wl,--no-whole-archive -n --static -Wl,--start-group -lrtthread -Wl,--end-group
#?<-

# Optimization and Compiler flags and commands
CROSS_COMPILE= arm-linux-musleabi- #?
CC= $(CROSS_COMPILE)gcc
CFLAGS = -Wall  $(MYCFLAGS) #add leak --atexit

# Debugging flags
DEBUG = -g

all: $(BUILDDIR) $(LIBFT) $(NAME)  

# Object dir rule
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Objects rule #remove libinc
$(BUILDDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(CFLAGS) -I$(LIBINC) -I$(INC) -o $@ -c $<    
					
# Project file rule
$(NAME): $(BUILDOBJS)
	$(CC) $(MYLDFLAGS) $(CFLAGS) -o $(NAME) $(BUILDOBJS) $(LIBFT)

# Libft rule
$(LIBFT):
	make -C $(LIBDIR)

# Cleaning up the build files
clean:
	rm -rf $(BUILDDIR)
	make -C $(LIBDIR) clean

# Getting rid of the project file
fclean: clean
	rm -rf $(NAME)
	make -C $(LIBDIR) fclean

# Do both of the above
re: fclean all

# Just in case those files exist in the root dir
.PHONY: all fclean clean re
