# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glicciar <glicciar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 20:53:10 by glicciar          #+#    #+#              #
#    Updated: 2024/11/06 22:07:39 by glicciar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_expander.a
CC = cc
FLAGS = -Wall -Wextra -Werror -gcc
OBJS = $(SRC: .c=.o)
RM = rm -f
SRC = ft_expander.c

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)	

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY		:	clean fclean re all

