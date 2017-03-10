# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/10 05:21:05 by aakin-al          #+#    #+#              #
#    Updated: 2017/03/10 05:35:02 by aakin-al         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SOURCE = fillit.c funcs.c

LIB = libft.a

O_FILES = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror $(SOURCE) $(LIB) -o $(NAME)

clean:
	@rm -f $(O_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all
