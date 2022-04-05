# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 17:07:54 by ebondi            #+#    #+#              #
#    Updated: 2022/04/05 20:02:15 by ebondi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = start.c utils.c
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror
MYLIB = mylib/mylib.a

$(NAME):
		make -C mylib
		gcc $(FLAGS) $(SRCS) $(MYLIB) -o $@
	
all : $(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME) $(MYLIB)
		make fclean -C mylib

re:		fclean all

.PHONY: all clean fclean re