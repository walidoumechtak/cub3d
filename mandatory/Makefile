# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 12:04:27 by hbenfadd          #+#    #+#              #
#    Updated: 2023/06/25 11:29:24 by woumecht         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= Cub3d
CC				= cc
CFLAGS			=  -Wall -Wextra -Werror -g -fsanitize=address
LIBFT_DIR		= ./libft
HEADER			= -I./inc -I./libft/inc  -I/usr/local/include 
CLIB			= -L./libft -lft -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit -lm 

RM				= rm -rf

PARSSING_SRCS	= ft_check_map.c get_map.c ft_check_map_wall.c ft_copy_map_to_rectangle_map.c  \
				  ft_clear_floor_ceiling.c ft_count_comma.c ft_convert_color.c\

RAYCAST_SRCS 	= draw_wall.c even_handler.c find_first_ray.c  floor_ciel.c init_point_hor.c \
					init_point_ver.c move_player.c movement.c my_mlx_pixel_put.c ray_cast_hor.c \
					ray_cast_ver.c ray_casting.c rays.c view_player.c angles_trans.c map_dim.c \

SRCS = $(addprefix ./srcs/parssing/, $(PARSSING_SRCS)) \
		$(addprefix ./srcs/raycasting/, $(RAYCAST_SRCS)) \
		main.c init.c \

OBJS = $(SRCS:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(HEADER) $(OBJS) $(CLIB)  -o $@

clean:
	$(RM) $(OBJS)
	
fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
re: fclean all
