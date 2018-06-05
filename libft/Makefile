# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 21:23:52 by jagarcia          #+#    #+#              #
#    Updated: 2018/04/29 16:41:46 by mrodrigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re ft_printf

NAME = libft.a

OBJ_DIR = objects/

SRC = ft_isascii.c \
	  ft_lstdelone.c \
	  ft_memchr.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_strcpy.c \
	  ft_strjoin.c	\
	  ft_strnjoin.c	\
	  ft_strnjoinfree.c	\
	  ft_strjoinfree.c	\
	  ft_strncmp.c \
	  ft_strsplit.c \
	  ft_isdigit.c \
	  ft_lstiter.c \
	  ft_memcmp.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_strdel.c \
	  ft_strlcat.c \
	  ft_strncpy.c \
	  ft_strstr.c \
	  ft_atoi.c \
	  ft_isprint.c \
	  ft_lstmap.c \
	  ft_memcpy.c \
	  ft_putendl.c \
	  ft_strcat.c \
	  ft_strdup.c \
	  ft_strlen.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_bzero.c \
	  ft_itoa.c \
	  ft_lstnew.c \
	  ft_memdel.c \
	  ft_putendl_fd.c \
	  ft_strchr.c \
	  ft_strequ.c \
	  ft_strmap.c \
	  ft_strnew.c \
	  ft_strtrim.c \
	  ft_isalnum.c \
	  ft_lstadd.c \
	  ft_memalloc.c \
	  ft_memmove.c \
	  ft_putnbr.c \
	  ft_strclr.c \
	  ft_striter.c \
	  ft_strmapi.c \
	  ft_strnstr.c \
	  ft_tolower.c \
	  ft_isalpha.c \
	  ft_islower.c \
	  ft_isupper.c \
	  ft_lstdel.c \
	  ft_memccpy.c \
	  ft_memset.c \
	  ft_putnbr_fd.c \
	  ft_strcmp.c \
	  ft_striteri.c \
	  ft_strncat.c \
	  ft_strrchr.c \
	  ft_toupper.c \
	  ft_lstsplit.c \
	  ft_lstnext.c \
	  ft_swap.c \
	  ft_pow.c \
	  ft_sort_pos_int.c \
	  ft_debug.c \
	  ft_debug_num.c \
	  ft_putbytes.c \
	  ft_wstrlen.c \
	  ft_strlen_free.c \
	  ft_issdigit.c \
	  ft_memjoinfree.c \
	  ft_abs.c \
	  ft_strinsert.c \
	  ft_strinsertfree.c \
	  ft_strcut.c \
	  ft_strcutfree.c \
	  ft_strinvert.c \
	  ft_error.c \
	  get_next_line.c \
	  ft_numint.c

OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC))

FT_PRINTF_DIR = ft_printf

all: $(NAME)

$(NAME): $(OBJ) $(FT_PRINTF_DIR)
	@ranlib $(NAME)

$(FT_PRINTF_DIR):
	$(MAKE) -C ft_printf

$(OBJ_DIR)%.o : %.c
	@gcc -Wall -Wextra -Werror -Iincludes -c $<
	@mkdir -p $(OBJ_DIR)
	@mv -f $(@F) $(OBJ_DIR)
	@ar rc $(NAME) $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)

re:	fclean
	@make
