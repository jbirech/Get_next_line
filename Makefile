# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jobirech <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/22 23:24:03 by jobirech          #+#    #+#              #
#    Updated: 2018/06/22 23:24:10 by jobirech         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAG = -Wall -Wextra -Werror -g -fsanitize=address -o

LIBFT = libft/

COMP = make -C $(LIBFT) re

COMPC = make -C $(LIBFT) clean

COMPF = make -C  $(LIBFT) fclean

NAME =	get_next_line

SRCS =	$(LIBFT)libft.a \
		get_next_line.c \
		main.c \

all: 	$(NAME)

$(NAME):
		@$(COMP)
		@$(CC) $(FLAG) $(NAME) $(SRCS)

clean:
		@$(COMPC)

fclean:	clean
		@$(COMPF)
		@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
