# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 11:12:37 by kbrechin          #+#    #+#              #
#    Updated: 2022/03/03 16:50:12 by kbrechin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_isalpha.c \
  	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_strlen.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strncmp.c \
	   ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memchr.c \
	   ft_memmove.c \
	   ft_memcmp.c \
	   ft_strlcpy.c \
	   ft_strlcat.c \
	   ft_strnstr.c \
	   ft_atoi.c \
	   ft_calloc.c \
	   ft_strdup.c \
	   ft_substr.c \
	   ft_strjoin.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@echo "$(NAME) has been created"
	@ranlib $(NAME)
	@echo "$(NAME) has been indexed"

%.o:%.c
	@gcc $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "OBJS have been deleted"

fclean: clean
	@rm -f $(OBJS)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re
