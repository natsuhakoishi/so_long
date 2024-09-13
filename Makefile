# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yyean-wa <yyean-wa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/09 13:11:53 by yyean-wa          #+#    #+#              #
#    Updated: 2024/09/04 17:43:32 by yyean-wa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
INCLUDE = -I include
LIBFT = cd libft && make
LIB = libft/libft.a
REMOVE = rm -rf
LBX = -lmlx -framework OpenGL -framework AppKit

SRCS = src/ft_exit.c src/ft_images.c src/ft_maps.c\
		src/ft_movement.c src/main.c src/split.c \
		src/floodfill.c
OBJS = $(SRCS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all:$(NAME)

$(NAME):$(OBJS)
	@$(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) $(LBX) -o $(NAME)

clean :
	@$(REMOVE) $(OBJS)
	@cd libft && make clean

fclean :clean
	@$(REMOVE) $(NAME)
	@cd libft && make fclean

re: fclean all

.PHONY: all clean fclean re