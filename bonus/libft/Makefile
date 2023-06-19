# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 11:25:18 by hbenfadd          #+#    #+#              #
#    Updated: 2023/05/07 17:58:55 by hbenfadd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CFLAGS		= -Wall -Werror -Wextra
CC			= cc 
RM			= rm -f
HEADER		= -I./inc
LIBFT_DIR	= ./libft/

SRC_LIBFT	= ft_atoi.c \
			  ft_bzero.c \
			  ft_calloc.c \
			  ft_itoa.c \
			  del.c\
			  ft_isalnum.c \
			  ft_isalpha.c \
			  ft_isascii.c \
			  ft_isdigit.c \
			  ft_isprint.c \
			  ft_memchr.c \
			  ft_memcmp.c \
			  ft_memcpy.c \
			  ft_memmove.c \
			  ft_memset.c \
			  ft_strchr.c \
			  ft_strdup.c \
			  ft_strlcat.c \
			  ft_strlcpy.c \
			  ft_strlen.c \
			  ft_strncmp.c \
			  ft_strnstr.c \
			  ft_strrchr.c \
			  ft_tolower.c \
			  ft_substr.c \
			  ft_strjoin.c \
			  ft_split.c \
			  ft_strtrim.c \
			  ft_putchar_fd.c \
			  ft_putstr_fd.c \
			  ft_putendl_fd.c \
			  ft_putnbr_fd.c \
			  ft_strmapi.c \
			  ft_striteri.c \
			  ft_toupper.c \
			  ft_lstnew_bonus.c \
			  ft_lstadd_front_bonus.c \
			  ft_lstsize_bonus.c \
			  ft_lstlast_bonus.c \
			  ft_lstadd_back_bonus.c \
			  ft_lstdelone_bonus.c \
			  ft_lstclear_bonus.c \
			  ft_lstmap_bonus.c \
			  ft_lstiter_bonus.c


SRCS	= $(addprefix $(LIBFT_DIR), $(SRC_LIBFT))

OBJS = $(SRCS:.c=.o)

all : $(NAME)
	
%.o:%.c
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(NAME) : $(OBJS) 
	ar rcs $(NAME) $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all
