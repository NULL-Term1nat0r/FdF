# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 22:55:36 by estruckm          #+#    #+#              #
#    Updated: 2023/03/09 00:06:33 by estruckm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS =	main.c \
		ft_fdf_atoi.c \
		ft_fdf_print_list.c \
		ft_draw.c \
		ft_get_arguments.c \
		ft_get_coordinates.c \
		ft_initialise_array.c \
		ft_keyboard_input.c \
		ft_putpixel_to_image.c \
		ft_key_bar.c \
		ft_create_image.c \
		ft_reset_image.c \
		ft_rotate.c \

CC = gcc
CCFLAG = -Wall -Werror -Wextra
# -fsanitize=address
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
LIB = -C ./libft/
GET = -C ./Get_next_line/
P_S = -C ./push_swap

SUCCESS_COLOR = \033[32m

OBJECT = $(SRCS:.c=.o)
D_SRCS = ./srcs/

all : $(NAME)

%.o:$(D_SRCS)%.c
	$(CC) $(CCFLAG) -I ./push_swap -I ./Get_next_line -I ./libft -I /includes -o $@ -c $<

$(NAME) : $(OBJECT)
	make $(LIB)
	make $(GET)
	make $(P_S)
	$(CC) $(CCFLAG) $(MLXFLAGS) $(OBJECT) push_swap/push_swap.a -lft Get_next_line/get_next_line_bonus.a -lft -L ./libft -lft -o $(NAME) -g -fsanitize=address
	echo "$(SUCCESS_COLOR)$(NAME) - Compiled with Success"

clean :
	@make clean $(P_S)
	@make clean $(LIB)
	@make clean $(GET)
	@echo "$(SUCCESS_COLOR)$(NAME) - Cleaned with Success"
	@/bin/rm -rf $(OBJECT)

fclean : clean
	@make fclean $(P_S)
	@make fclean $(LIB)
	@make fclean $(GET)
	@rm -rf ./$(NAME)
	@echo "$(SUCCESS_COLOR)$(NAME) - FCleaned with Success"

re : fclean all

.PHONY: all clean fclean re
