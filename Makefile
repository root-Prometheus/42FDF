# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egunday <egunday@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 05:39:08 by egunday           #+#    #+#              #
#    Updated: 2023/01/07 07:26:52 by egunday          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC = /usr/include
INCLIB = $(INC)/minilibx-linux/lib
INCLUDES = ft_fdf.h

MAC_MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
MAC_MINILIBX_DIRECTORY = minilibx_macos
MAC_MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I$(INC) -g -Ilibft

NAME = fdf
SRCS = ft_fdf.c ft_parser.c ft_draw.c ft_transforms.c ft_utils.c ft_controls.c ft_draw_text.c menu.c fdfdvm.c
OBJS = $(SRCS:%.c=%.o)

UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
	# MacOS
	LFLAGS = -lmlx -lm -L$(MAC_MINILIBX_DIRECTORY) -framework OpenGL -framework AppKit
else
	# Linux
	LFLAGS = -Lminilibx-linux -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd
	CFLAGS += -Iminilibx-linux
endif

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $<

$(NAME): $(OBJS)
	@make -C libft
	$(CC) -o $(NAME) $(OBJS) $(LFLAGS) libft/libft.a

all: $(NAME)

clean:
	@make -C minilibx_macos clean
	@make -C libft clean
	$(RM) $(OBJS)

fclean: clean
	@make -C minilibx_macos clean
	$(RM) minilibx-linux/libmlx.a
	$(RM) minilibx-linux/libmlx_Linux.a
	@make -C libft fclean
	$(RM) $(NAME)

re: clean all

norme:
	norminette $(SRCS) ft_fdf.h
	norminette libft/*.c libft/*.h

bonus: $(NAME)
