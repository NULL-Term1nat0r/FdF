# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 23:46:22 by estruckm          #+#    #+#              #
#    Updated: 2023/02/25 02:25:31 by estruckm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line_bonus.a

COMPILATION = gcc -c -Wall -Wextra -Werror

SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(COMPILATION) $(SRCS) -I .
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

#@$(CC) $(CCFLAG) -I./Get_next_line -I./libft -I/includes -o $@ -c $<
