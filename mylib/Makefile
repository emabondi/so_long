# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 11:26:27 by ebondi            #+#    #+#              #
#    Updated: 2022/04/06 17:40:05 by ebondi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	mylib.a
SRCS =	ft_printf.c letter_resolver.c flag_resolver.c
OBJS =	$(SRCS:.c=.o)
FLAGS =	-Wall -Wextra -Werror
LIBFT =	libft.a
GNL = gnl/get_next_line.c gnl/get_next_line_utils.c
GNL_OBJS = get_next_line.o get_next_line_utils.o
GNL_FLAGS = -D BUFFER_SIZE=42

$(NAME):
		make -C libft
		cp libft/libft.a $(NAME)
		gcc -c $(FLAGS) $(SRCS) $(GNL) $(GNL_FLAGS)
		ar rc $(NAME) $(OBJS) $(GNL_OBJS)
		ranlib $(NAME)

bonus:	all

all: 	$(NAME)

clean:	
		rm -f $(OBJS) $(GNL_OBJS)
	
fclean:	clean
		rm -f $(NAME) $(LIBFT)
		make fclean -C libft
	
re:		fclean all

.PHONY: all clean fclean re bonus