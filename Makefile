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

SOURCE = fillit.c funcs.c split.c ft_strstr.c isvalid.c

LIB = libft.a

O_FILES = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(O_FILES)
	@gcc -c -o $(O_FILES) $(SOURCE) fillit.h
	@gcc -Wall -Wextra -Werror -o $(0_FILES) $(SOURCE) 

clean:
	@rm -f $(O_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all
