# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 12:04:27 by hbenfadd          #+#    #+#              #
#    Updated: 2023/06/19 14:35:00 by woumecht         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Cub3d
UNAME_S := $(shell uname -s)
CC			= cc
CFLAGS		=  -Wall -Wextra -Werror -fsanitize=address
LIBFT_DIR	= ./libft
HEADER		= -I./inc -I./libft/inc  -I/usr/local/include 
# Default for macOS
CLIB		= -L./libft -lft -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit -lm 
# Conditionally set CLIB for Linux
ifeq ($(UNAME_S),Linux)
	CLIB		= -L./libft -lft -L/usr/local/lib -lmlx -lXext -lX11 -lm
endif

RM		= rm -rf

PARSSING_SRCS	= ft_check_map.c get_map.c ft_check_map_wall.c ft_copy_map_to_rectangle_map.c  \

RAYCAST = draw_line.c draw_player.c draw_rectangle.c draw_wall.c drawing.c even_handler.c find_first_ray.c \
floor_ciel.c init_point_hor.c init_point_ver.c move_player.c movement.c my_mlx_pixel_put.c ray_cast_hor.c \
ray_cast_ver.c ray_casting.c rays.c update_cord.c view_player.c angles_trans.c map_dim.c \

SRCS = $(addprefix ./srcs/parssing/, $(PARSSING_SRCS)) \
		$(addprefix ./srcs/raycasting/, $(RAYCAST)) \
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
