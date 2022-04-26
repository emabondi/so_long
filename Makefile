# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 17:07:54 by ebondi            #+#    #+#              #
#    Updated: 2022/04/26 18:56:27 by ebondi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = start.c utils.c convert_images.c draw.c movements.c utils2.c
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror -l mlx -framework openGL -framework AppKit
MYLIB = mylib/mylib.a

$(NAME):
		make -C mylib
		gcc $(FLAGS) $(SRCS) $(MYLIB) -o $(NAME)
	
all : $(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME) $(MYLIB)
		make fclean -C mylib

re:		fclean all

.PHONY: all clean fclean re