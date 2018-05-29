LOG_CLEAR		= \033[2K
LOG_UP 			= \033[A
LOG_NOCOLOR		= \033[0m
LOG_BLACK		= \033[1;30m
LOG_RED			= \033[1;31m
LOG_GREEN		= \033[1;32m
LOG_YELLOW		= \033[1;33m
LOG_BLUE		= \033[1;34m
LOG_VIOLET		= \033[1;35m
LOG_CYAN		= \033[1;36m
LOG_WHITE		= \033[1;37m

.PHONY: clean $(NAME) re fclean all
.SILENT:

# comp
NAME = checker
CC = clang
LIBCC = make -C ../libft
CCFLAGS = -Wall -Wextra -Werror #-fsanitize=adress -g


# dir
D_SRC = srcs
D_INC = includes
D_LIB = ../libft

# flags
F_LIB = -lft 

# sources
SRC =\
     checker.c \
     get_ope.c \
     get_chain.c \
     utils.c \
     swap.c \
     push.c \
     rotate.c \
     exec_operation.c \

INC = $(addprefix -I,$(D_INC))
LIB_INC = $(addprefix -I,$(addprefix $(D_LIB)/,$(D_INC)))
SRCS = $(addprefix $(D_SRC)/,$(SRC))

# special chars
all: libft $(NAME)

libft: 
	$(MAKE) -C ../libft

$(NAME): comp

comp: 
	$(CC) -o $(NAME) $(SRCS) $(INC) $(LIB_INC) -L$(D_LIB) $(F_LIB)

clean:
	rm -Rf $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all
