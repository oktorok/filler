# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 17:20:08 by jagarcia          #+#    #+#              #
#    Updated: 2018/06/06 03:26:20 by mrodrigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re graf

NAME = jagarcia.filler

GRAF_NAME = interface

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

MAIN_FUNCS = main.c \
			 ft_seek.c \
			 ft_ndigits.c \
			 map_reader.c \
			 update_map.c \
			 write_test.c \
			 update_piece.c \
			 ft_roundup.c \
			 put_piece.c \
			 check_position.c \
			 piece_point.c \
			 print_solution.c \
			 cord_piece_to_map.c \
			 aproach_strat.c

GRAPHIC_FUNCS = main_graphic.c \
				ft_print_map.c \
				ft_get_addrs.c \
				ft_initialice.c \
				jump_copy.c \
				placer.c \
				ft_set_piece_pos.c \
				ft_get_piece.c \
				ft_info.c \
				ft_set_bricks.c \
				ft_keys.c \
				ft_progress.c \
				ft_set_xpm.c \
				ft_seek.c \
				ft_ndigits.c

OBJ_DIR = objects/
LIBFT_DIR = libft/
MAIN_DIR = srcs/
INCLUDES_DIR = includes/
GRAPHIC_DIR = srcs/graphics/


LIBFT_NAME = libft.a
LIBFT_ABREV = ft
HEADERS = filler.h \
			graphics.h

HEADER_PATH = $(patsubst %.h, $(INCLUDES_DIR)%.h,$(HEADERS))
MAIN_OBJ = $(patsubst %.c, $(OBJ_DIR)%.o,$(MAIN_FUNCS))
GRAPHIC_OBJ = $(patsubst %.c, $(OBJ_DIR)%.o,$(GRAPHIC_FUNCS))

OBJ = $(MAIN_OBJ) $(GRAPHIC_OBJ)


all : $(NAME)

$(NAME) : $(MAIN_OBJ) $(LIBFT_DIR)$(LIBFT_NAME) $(GRAF_NAME)
	gcc $(MAIN_OBJ) -L$(LIBFT_DIR) -l$(LIBFT_ABREV) -I$(INCLUDES_DIR) $(CFLAGS) -o $(NAME)

$(GRAF_NAME): $(GRAPHIC_OBJ)
	gcc $(GRAPHIC_OBJ) $(MLXFLAGS) -L$(LIBFT_DIR) -l$(LIBFT_ABREV) -I$(INCLUDES_DIR) $(CFLAGS) -o $(GRAF_NAME)

$(LIBFT_DIR)$(LIBFT_NAME):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)%.o : $(MAIN_DIR)%.c $(HEADER_PATH)
	gcc $(CFLAGS) -c -I $(INCLUDES_DIR) $<
	mkdir -p $(OBJ_DIR)
	mv -f $(@F) $(OBJ_DIR)

$(OBJ_DIR)%.o : $(GRAPHIC_DIR)%.c $(HEADER_PATH)
	gcc $(CFLAGS) -c -I $(INCLUDES_DIR) $<
	mkdir -p $(OBJ_DIR)
	mv -f $(@F) $(OBJ_DIR)

clean:
	rm -f $(OBJ_SRC)
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f filler.trace
	rm -f $(NAME)
	rm -f $(GRAF_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean
	make

exe: $(NAME)
	@sh start.sh
