# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 20:32:02 by eleotard          #+#    #+#              #
#    Updated: 2022/09/05 14:10:45 by lcalvie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

BONUS	= so_long_bonus

SRCS	= main_and_init.c			\
			get_next_line.c			\
			get_next_line_utils.c	\
			error_gestion.c			\
			check_valid_map.c		\
			check_valid_path.c		\
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
			check_valid_path.c		\
			check_parsing_bonus.c 		\
			so_long_utils_bonus.c			\
			map_material_bonus.c			\
			struct_init_bonus.c 			\
			hook_fonctions_bonus.c		\
			moves_bonus.c 				\
			swap_count_display_bonus.c 	\


OBJS	= ${SRCS:%.c=%.o}

OBJS_BONUS	= ${SRCS_BONUS:%.c=%.o}

MLX		= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz 

LIBFT	= -Llibft -lft

CFLAGS	= -g3 -Wall -Werror -Wextra

CC		= gcc

RM		= rm -f

all: ${NAME}

${NAME}: ${OBJS} libft/libft.a mlx_linux/libmlx_Linux.a
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT} ${MLX}

#malloc_test: $(OBJS) libft/libft.a mlx_linux/libmlx_Linux.a
#	$(CC) $(CFLAGS) -fsanitize=undefined -rdynamic -o $@ ${OBJS} ${MLX} ${LIBFT} -L. -lmallocator

bonus: ${BONUS}

${BONUS}: ${OBJS_BONUS} libft/libft.a mlx_linux/libmlx_Linux.a
	${CC} ${CFLAGS} -o ${BONUS} ${OBJS_BONUS} ${LIBFT} ${MLX}

%.o: %.c 
	${CC} ${CFLAGS} -I/usr/include -Imlx_linux -c $< -o $@

libft/libft.a:
	make -C libft

mlx_linux/libmlx_Linux.a:
	make -C mlx_linux

clean:
	make -C libft clean
	make -C mlx_linux clean
	${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	make -C libft fclean
	${RM} ${NAME} ${BONUS}

re:	fclean all

.PHONY: all re fclean clean
