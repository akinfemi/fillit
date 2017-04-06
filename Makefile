# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/10 05:21:05 by aakin-al          #+#    #+#              #
#    Updated: 2017/04/06 02:13:55 by aakin-al         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SOURCE = fillit.c\
		 funcs.c\
		 split.c\
		 ft_strstr.c\
		 isvalid.c\
		 remove_tet.c\
		 solve.c

LIB = libft/libft.a

O_FILES = $(SOURCE:.c=.o)

all: $(NAME)

$(LIB):
	@make -C libft

$(NAME): $(LIB) $(O_FILES)
	@gcc -Wall -Wextra -Werror $(O_FILES) $(LIB) -o $(NAME)  

%.o: %.c
	@gcc -Wall -Werror -Wextra -c $^

clean:
	@rm -f $(O_FILES)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all
