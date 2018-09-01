# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/04 13:10:20 by abbenham          #+#    #+#              #
#    Updated: 2018/08/17 16:02:37 by abbenham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##########################################################################
##########################################################################
##########################################################################
##########################################################################

#.PHONY: clean $(NAME) re fclean all
#.SILENT:

NAME = libft.a

# compilation
CC = clang
FLAGS =  -Wall -Werror -Wextra # -Ofast # -O3

# dir
D_SRC = srcs
D_INC = includes
D_OBJ = objs

# sources
SRC =\
     strings/ft_strncat.c \
     strings/manage_tab.c \
     strings/ft_strnstr.c \
     strings/ft_putstr_fd.c \
     strings/ft_strequ.c \
     strings/ft_strlen.c \
     strings/ft_strclr.c \
     strings/ft_strsplit.c \
     strings/ft_strnlen.c \
     strings/ft_strchr.c \
     strings/ft_striteri.c \
     strings/ft_strjoin.c \
     strings/ft_strstr.c \
     strings/ft_putendl.c \
     strings/ft_strcat.c \
     strings/ft_putendl_fd.c \
     strings/ft_strdel.c \
     strings/ft_strnequ.c \
     strings/ft_strrchr.c \
     strings/ft_strmap.c \
     strings/ft_strncmp.c \
     strings/ft_strcpy.c \
     strings/ft_strmapi.c \
     strings/ft_strtrim.c \
     strings/ft_strnew.c \
     strings/ft_putstr.c \
     strings/ft_strlcat.c \
     strings/ft_strdup.c \
     strings/ft_striter.c \
     strings/ft_strsub.c \
     strings/ft_strncpy.c \
     strings/ft_strcmp.c \
     numbers/ft_putnbr.c \
     numbers/ft_putnbr_base.c \
     numbers/ft_putnbr_ill.c \
     numbers/ft_putnuminfo.c \
     numbers/ft_putnbr_fd.c \
     numbers/ft_atoi.c \
     numbers/ft_itoa.c \
     numbers/ft_itoa_base.c \
     numbers/ft_nbrlen.c \
     numbers/ft_print_adress.c \
     memory/ft_freetab.c \
     memory/ft_memcmp.c \
     memory/ft_bzero.c \
     memory/ft_memcpy.c \
     memory/ft_memalloc.c \
     memory/ft_memccpy.c \
     memory/ft_memchr.c \
     memory/ft_memset.c \
     memory/ft_memdel.c \
     memory/ft_memmove.c \
     file/ft_display_file.c \
     file/get_next_line.c \
     chars/ft_isdigit.c \
     chars/ft_isascii.c \
     chars/ft_isprint.c \
     chars/ft_toupper.c \
     chars/ft_putchar.c \
     chars/ft_isalpha.c \
     chars/ft_putchar_fd.c \
     chars/ft_isalnum.c \
     chars/ft_tolower.c \
     utf8/ft_putchar_utf8.c \
     utf8/ft_putstr_utf8.c \
     utf8/ft_strlen_utf8.c \
     utf8/utf8_to_s.c \
     printf/ft_printf.c \
     printf/main_assets.c \
     printf/kitchen.c \
     printf/kitchen_o.c \
     printf/kitchen_x.c \
     printf/kitchen_integers.c \
     printf/kitchen_unicode.c \
     printf/extract_data.c \
     printf/c_on_trunk.c \
     printf/wc_on_trunk.c \
     printf/s_on_trunk.c \
     printf/d_on_trunk.c \
     printf/u_on_trunk.c \
     printf/o_on_trunk.c \
     printf/x_on_trunk.c \
     printf/ws_on_trunk.c \
     printf/mod_on_trunk.c \
     list/ft_lstpushiter.c\
     list/ft_lstnew.c\
     list/ft_lstlast.c\
     list/ft_lstdup.c\
     list/ft_lstaddback.c\
     list/ft_lstpushafter.c\
     list/ft_arraytolst.c\
     list/ft_lstiter.c\
     list/ft_lstpushback.c\
     list/ft_lstpushfront.c\
     list/ft_lstmap.c\
     list/ft_lstadditer.c\
     list/ft_lstdelback.c\
     list/ft_lstremback.c\
     list/ft_lstaddfront.c\
     list/ft_lstdel.c\
     list/ft_lstpushby.c\
     list/ft_lstshift.c\
     list/ft_lstfold.c\
     list/ft_lstaddafter.c\
     list/ft_lstlen.c\
     list/ft_lstaddby.c\
     list/ft_lsttoarray.c\
     list/ft_lstprint.c\


OBJS= $(addprefix $(D_OBJ)/, $(addsuffix .o, $(basename $(SRC))))
OBJS_DIRS = $(sort $(dir $(OBJS)))
INC = $(addprefix -I, $(D_INC))

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

dirs:
	mkdir -p objs
	mkdir -p $(OBJS_DIRS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(D_OBJ)/%.o: $(D_SRC)/%.c
	$(CC) -c -o $@ $< $(INC) $(FLAGS)

##########################################################################
##########################################################################
##########################################################################
##########################################################################
