# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 22:55:36 by estruckm          #+#    #+#              #
#    Updated: 2023/02/25 03:30:06 by estruckm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS = main.c \


CC = gcc
CCFLAG = -Wall -Werror -Wextra
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
LIB = -C ./libft/
GET = -clean ./Get_next_line/

SUCCESS_COLOR = \033[32m

OBJECT = $(SRCS:.c=.o)
D_SRCS = ./srcs/

all : $(NAME)

%.o:$(D_SRCS)%.c
	@$(CC) $(CCFLAG) -I./Get_next_line -I./libft -I/includes -o $@ -c $<

$(NAME) : $(OBJECT)
	@make $(LIB)
	@make $(GET)
	@$(CC) $(CCFLAG) $(MLXFLAGS) -o $(NAME) $(OBJECT) -L./Get_next_line -lft -L./libft -lft
	@echo "$(SUCCESS_COLOR)$(NAME) - Compiled with Success"

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

