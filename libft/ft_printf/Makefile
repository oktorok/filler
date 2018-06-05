# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 17:20:08 by jagarcia          #+#    #+#              #
#    Updated: 2018/04/29 16:39:57 by mrodrigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : compile norme all clean fclean re

FLAGS = -Wall -Wextra -Werror 

MAIN_FUNCS = ft_printf.c \
			 ft_asprintf.c \
			 ft_dprintf.c

FORMATS = ft_field_format.c \
		  ft_space_format.c \
		  ft_plus_format.c \
		  ft_hash_format.c \
		  ft_apostrophe_format.c \
		  ft_zero_format.c \
		  ft_search_zero_format.c \
		  ft_asterisc_format.c \
		  ft_minus_format.c

MODS = ft_l_mod.c \
	   ft_mods.c \
	   ft_h_mod.c \
	   ft_ll_mod.c \
	   ft_hh_mod.c \
	   ft_j_mod.c \
	   ft_z_mod.c \
	   ft_none_mod.c

UTILS = ft_wchar.c \
		ft_utf8.c \
		ft_locate_pointer.c \
		ft_locate_date.c \
		ft_dectobin.c \
		ft_dectooct.c \
		ft_dectohex.c \
		ft_printmemory.c \
		ft_colors.c \
		ft_ajust_params.c \
		ft_ultoa_base.c \
		ft_ltoa_base.c \
		ft_findend.c

UTILS_FLOAT = ft_choose_power.c \
			  ft_dtomyd.c \
			  ft_grisu.c \
			  ft_sige.c \
			  ft_take_power.c \
			  ft_multiply.c \
			  ft_round.c \
			  ft_putthepoint.c

TYPES = ft_sls_type.c \
		ft_clc_type.c \
		ft_ilidld_type.c \
		ft_xlx_type.c \
		ft_p_type.c \
		ft_oloulu_type.c \
		ft_n_type.c \
		ft_b_type.c \
		ft_r_type.c \
		ft_percent_type.c \
		ft_feleglg_type.c \
		ft_m_type.c \
		ft_error_type.c

LIBFT = libft.a
LIBFT_DIR = ../
TYPES_DIR = srcs/types/
FORMATS_DIR = srcs/formats/
MODS_DIR = srcs/mods/
UTILS_DIR = srcs/utils/
UTILS_FLOAT_DIR = $(UTILS_DIR)utils_float/
MAINS_DIR = srcs/
INCLUDES_DIR = includes/


OBJ_DIR = ../objects/
MAINS_OBJ = $(patsubst %.c, $(OBJ_DIR)%.o,$(MAIN_FUNCS))
FORMATS_OBJ = $(patsubst %.c, $(OBJ_DIR)%.o,$(FORMATS))
TYPES_OBJ = $(patsubst %.c, $(OBJ_DIR)%.o,$(TYPES))
MODS_OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(MODS))
UTILS_OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(UTILS))
UTILS_FLOAT_OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(UTILS_FLOAT))
OBJ = $(MAINS_OBJ) $(FORMATS_OBJ) $(TYPES_OBJ) $(LIBFT_OBJ) $(MODS_OBJ) $(UTILS_OBJ) $(UTILS_FLOAT_OBJ)

$(LIBFT_DIR)$(LIBFT) : $(OBJ)

$(OBJ_DIR)%.o : $(MAINS_DIR)%.c
	gcc $(FLAGS) -I$(INCLUDES_DIR) -c $<
	mkdir -p $(OBJ_DIR)
	mv -f $(@F) $(OBJ_DIR)
	ar -rs $(LIBFT_DIR)$(LIBFT) $@

$(OBJ_DIR)%.o : $(FORMATS_DIR)%.c
	gcc $(FLAGS) -I$(INCLUDES_DIR) -c $<
	mkdir -p $(OBJ_DIR)
	mv -f $(@F) $(OBJ_DIR)
	ar -rs $(LIBFT_DIR)$(LIBFT) $@ 

$(OBJ_DIR)%.o : $(TYPES_DIR)%.c
	gcc $(FLAGS) -I$(INCLUDES_DIR) -c $<
	mkdir -p $(OBJ_DIR)
	mv -f $(@F) $(OBJ_DIR)
	ar -rs $(LIBFT_DIR)$(LIBFT) $@ 

$(OBJ_DIR)%.o : $(UTILS_DIR)%.c
	gcc $(FLAGS) -I$(INCLUDES_DIR) -c $<
	mkdir -p $(OBJ_DIR)
	mv -f $(@F) $(OBJ_DIR)
	ar -rs $(LIBFT_DIR)$(LIBFT) $@ 

$(OBJ_DIR)%.o : $(UTILS_FLOAT_DIR)%.c
	gcc $(FLAGS) -I$(INCLUDES_DIR) -c $<
	mkdir -p $(OBJ_DIR)
	mv -f $(@F) $(OBJ_DIR)
	ar -rs $(LIBFT_DIR)$(LIBFT) $@ 

$(OBJ_DIR)%.o : $(MODS_DIR)%.c
	gcc $(FLAGS) -I$(INCLUDES_DIR) -c $<
	mkdir -p $(OBJ_DIR)
	mv -f $(@F) $(OBJ_DIR)
	ar -rs $(LIBFT_DIR)$(LIBFT) $@

clean:
	rm -f $(OBJ)

fclean: clean

re: fclean
	make
