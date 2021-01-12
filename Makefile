# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/08 19:17:51 by aez-zaou          #+#    #+#              #
#    Updated: 2020/11/10 09:12:17 by aez-zaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		cub3D

SRCS		=		./src/gnl/get_next_line.c ./src/my_libft/ft_atoi.c\
 ./src/my_libft/ft_bzero.c ./src/my_libft/ft_isalpha.c ./src/my_libft/ft_calloc.c\
 ./src/my_libft/ft_memcpy.c ./src/my_libft/ft_memccpy.c ./src/my_libft/ft_putchar_fd.c\
 ./src/my_libft/ft_putstr_fd.c ./src/my_libft/ft_strlen.c ./src/my_libft/ft_strncmp.c\
 ./src/my_libft/ft_substr.c ./src/gnl/get_next_line_utils.c\
 ./src/my_libft/ft_isdigit.c ./src/my_libft/ft_split.c ./src/bmp.c\
 ./src/find_player.c ./src/create_map.c ./src/exit.c ./src/draw_game.c\
 ./src/initialise_data.c ./src/main.c ./src/keys.c ./src/map_errors.c\
 ./src/sprites.c ./src/ray_casting.c ./src/sprites1.c ./src/read_info.c\

OBJS		=		bmp.o ft_atoi.o ft_memccpy.o ft_strlen.o initialise_data.o\
	read_info.o create_map.o ft_bzero.o ft_memcpy.o ft_strncmp.o keys.o\
	sprites.o draw_game.o ft_calloc.o ft_putchar_fd.o ft_substr.o main.o\
	sprites1.o exit.o ft_isalpha.o ft_putstr_fd.o get_next_line.o map_errors.o\
	find_player.o ft_isdigit.o ft_split.o get_next_line_utils.o ray_casting.o\

all: $(NAME)

$(NAME): $(SRCS)
	gcc -Wall -Wextra -Werror -c $(SRCS)
	gcc $(OBJS) -lmlx -framework OpenGL -framework AppKit -Ofast -o $(NAME)

bonus: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all