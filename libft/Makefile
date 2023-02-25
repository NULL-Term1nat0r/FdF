# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 14:44:41 by estruckm          #+#    #+#              #
#    Updated: 2023/02/25 02:42:40 by estruckm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
# Name des kompilierten Programms
COMPILATION = gcc -c -Wall -Wextra -Werror

SRCS	=	 ft_itoa.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_striteri.c ft_strmapi.c ft_split.c ft_strtrim.c ft_strjoin.c ft_substr.c ft_strdup.c ft_memmove.c ft_atoi.c ft_calloc.c ft_strnstr.c ft_memset.c ft_memcmp.c ft_memchr.c ft_strncmp.c ft_strrchr.c ft_strchr.c ft_toupper.c ft_tolower.c ft_strlcat.c ft_strlcpy.c ft_memcpy.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_strlen.c ft_lstmap.c ft_lstiter.c ft_lstclear.c ft_lstdelone.c ft_lstadd_back.c ft_lstlast.c ft_lstadd_front.c ft_lstnew.c ft_lstsize.c
# Hier alle zu kompilierenden .c-Dateien erfassen
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

