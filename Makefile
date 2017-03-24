# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/10 05:21:05 by aakin-al          #+#    #+#              #
#    Updated: 2017/03/24 14:02:57 by aakin-al         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SOURCE = fillit.c funcs.c split.c ft_strstr.c isvalid.c

LIB = libft.a

O_FILES = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(O_FILES)
	@gcc -Wall -Wextra -Werror $(O_FILES) $(LIB) -o $(NAME)  

clean:
	@rm -f $(O_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all
