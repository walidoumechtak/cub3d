# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 12:04:27 by hbenfadd          #+#    #+#              #
#    Updated: 2023/06/23 11:23:03 by woumecht         ###   ########.fr        #
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

PARSSING_SRCS	= ft_check_map_bonus.c get_map_bonus.c ft_check_map_wall_bonus.c ft_copy_map_to_rectangle_map_bonus.c\

RAYCAST = draw_line_bonus.c  draw_wall_bonus.c even_handler_bonus.c find_first_ray_bonus.c \
floor_ciel_bonus.c init_point_hor_bonus.c init_point_ver_bonus.c mini_map_bonus.c move_player_bonus.c movement_bonus.c my_mlx_pixel_put_bonus.c ray_cast_hor_bonus.c \
ray_cast_ver_bonus.c ray_casting_bonus.c rays_bonus.c view_player_bonus.c angles_trans_bonus.c map_dim_bonus.c open_dor_bonus.c kill_thread.c \
animation_inc.c controlle_speed.c close_door.c \

SRCS = $(addprefix ./srcs/parssing/, $(PARSSING_SRCS)) \
		$(addprefix ./srcs/raycasting/, $(RAYCAST)) \
		main_bonus.c init_bonus.c \

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
