# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/30 20:16:52 by edbarbos          #+#    #+#              #
#    Updated: 2020/12/03 17:02:40 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = *.c

OBJECTS = *.o

LIB = ft_printf.h

all: $(NAME)

$(NAME): $(OBJECTS)

$(OBJECTS) : $(SRCS) $(LIB)
	@gcc -Wextra -Werror -Wall -c -g -I . $(LIB) $(SRCS)
	@ar rcs $(NAME) $(OBJECTS)

clean:
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf *.gch

re: fclean all