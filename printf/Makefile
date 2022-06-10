# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 16:16:23 by kbrechin          #+#    #+#              #
#    Updated: 2022/06/10 19:11:41 by kbrechin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = ft_printf.c\
		ft_itoh.c\
		ft_putnbr.c\
		ft_putstr.c\

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

create:
	@clear
	@gcc *.c -o run
	@./run

.PHONY:			all clean fclean re
