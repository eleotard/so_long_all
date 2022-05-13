# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 20:32:02 by eleotard          #+#    #+#              #
#    Updated: 2022/05/13 21:47:41 by eleotard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRCS	= main_and_init.c			\
			get_next_line.c			\
			get_next_line_utils.c	\
			error_gestion.c			\
			check_valid_map.c		\
			check_parsing.c 		\
			so_long_utils.c			\
			map_material.c			\
			struct_init.c 			\
			hook_fonctions.c		\
			moves.c 				\
			swap_count_display.c 	\

SRCS_BONUS	= main_and_init_bonus.c			\
			get_next_line_bonus.c			\
			get_next_line_utils_bonus.c	\
			error_gestion_bonus.c			\
			check_valid_map_bonus.c		\
			check_parsing_bonus.c 		\
			so_long_utils_bonus.c			\
			map_material_bonus.c			\
			struct_init_bonus.c 			\
			hook_fonctions_bonus.c		\
			moves_bonus.c 				\
			swap_count_display_bonus.c 	\


OBJ	= ${SRCS:%.c=%.o}

OBJ_BONUS	= ${SRCS_BONUS:%.c=%.o}

MLX		= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz 

LIBFT	= -Llibft -lft

CFLAGS	= -Wall -Werror -Wextra

CC		= clang

RM		= rm -f

all: ${NAME}

${NAME}: ${OBJ} libft/libft.a mlx_linux/libmlx_Linux.a
	${CC} ${CFLAGS} -o ${NAME} ${OBJ} ${LIBFT} ${MLX}
	
bonus: ${OBJ_BONUS} libft/libft.a mlx_linux/libmlx_Linux.a
	${CC} ${CFLAGS} -o ${NAME} ${OBJ_BONUS} ${LIBFT} ${MLX}

%.o: %.c 
	${CC} ${CFLAGS} -I/usr/include -Imlx_linux -c $< -o $@

libft/libft.a:
	make -C libft

mlx_linux/libmlx_Linux.a:
	make -C mlx_linux

clean:
	make -C libft clean
	make -C mlx_linux clean
	${RM} ${OBJ} ${OBJ_BONUS}

fclean: clean
	make -C libft fclean
	${RM} ${NAME}

re:	fclean all

.PHONY: all re fclean clean
