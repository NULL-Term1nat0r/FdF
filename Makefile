# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 22:55:36 by estruckm          #+#    #+#              #
#    Updated: 2023/03/23 19:59:14 by estruckm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS =	main.c \
		ft_fdf_atoi.c \
		ft_draw.c \
		ft_get_arguments.c \
		ft_get_coordinates.c \
		ft_initialise_array.c \
		ft_keyboard_input.c \
		ft_putpixel_to_image.c \
		ft_key_bar.c \
		ft_reset_image.c \
		ft_input.c \
		ft_gettime.c \
		ft_free.c \
		ft_get_coordinates_utils.c \
		ft_trigonomic_utils.c \
		ft_draw_utils.c \
		ft_key_bar_utils.c \

CC = gcc
CCFLAG = -Wall -Werror -Wextra -g
# -fsanitize=address
#-g -fprofile-instr-generate -fcoverage-mapping
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
LIB = -C ./libft
GET = -C ./Get_next_line/

SUCCESS_COLOR = \033[32m

OBJECT = $(SRCS:.c=.o)
D_SRCS = ./srcs/

all : $(NAME)

%.o:$(D_SRCS)%.c
	$(CC) $(CCFLAG) -o $@ -c $<

$(NAME) : $(OBJECT)
	make $(LIB)
	make $(GET)
	$(CC) $(CCFLAG) -g $(MLXFLAGS)  $(OBJECT) ./Get_next_line/get_next_line_bonus.a ./libft/libft.a -o $(NAME)
	echo "$(SUCCESS_COLOR)$(NAME) - Compiled with Success"

clean :
	@make clean $(LIB)
	@make clean $(GET)
	@echo "$(SUCCESS_COLOR)$(NAME) - Cleaned with Success"
	@/bin/rm -rf $(OBJECT)

fclean : clean
	@make fclean $(LIB)
	@make fclean $(GET)
	@rm -rf ./$(NAME)
	@echo "$(SUCCESS_COLOR)$(NAME) - FCleaned with Success"

re : fclean all

.PHONY: all clean fclean re

#Get_next_line/get_next_line_bonus.a
