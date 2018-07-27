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
VIEW_STACK = view_stack
CHECKER = checker
PS = push_swap
CC = clang
LIBCC = make -C ../libft
CCFLAGS = -Wall -Wextra -Werror #-fsanitize=adress -g

# dir
D_SRC = srcs
GO_SRC = gui
D_INC = includes
D_LIB = ../libft

# flags
F_LIB = -lft 

# sources
CHECKER_SRC =\
     checker.c \
     parser.c \
     push.c \
     swap.c \
     rotate.c \
     reverse.c \
     is_sorted.c \
     ope_utils.c \
     utils.c \

PS_SRC=\
     push_swap.c \
     ope_utils.c \
     is_sorted.c \
     utils.c \
     parser.c \
     push.c \
     swap.c \
     rotate.c \
     reverse.c \
     quick_sort.c \
     insert_sort.c \

VIEW_SRC=\
 	view_stack.go \

INC = $(addprefix -I,$(D_INC))
LIB_INC = $(addprefix -I,$(addprefix $(D_LIB)/,$(D_INC)))
CHECKER_SRCS = $(addprefix $(D_SRC)/,$(CHECKER_SRC))
PS_SRCS= $(addprefix $(D_SRC)/,$(PS_SRC))
VIEW_SRCS= $(addprefix $(GO_SRC)/,$(VIEW_SRC))

# special chars
all: libft $(CHECKER) $(PS) $(VIEW_STACK)

libft: 
	$(MAKE) -C ../libft

$(CHECKER): comp_checker
$(PS): comp_ps
$(VIEW_STACK): comp_view_stack

comp_checker: 
	$(CC) -o $(CHECKER) $(CHECKER_SRCS) $(INC) $(LIB_INC) -L$(D_LIB) $(F_LIB)

comp_ps: 
	$(CC) -o $(PS) $(PS_SRCS) $(INC) $(LIB_INC) -L$(D_LIB) $(F_LIB)

comp_view_stack:
	echo "view stack ok"
	##go build $(VIEW_SRCS)

clean:
	rm -Rf $(CHECKER) $(PS) $(VIEW_STACK)

fclean: clean
	rm -f $(NAME)

re: fclean all
