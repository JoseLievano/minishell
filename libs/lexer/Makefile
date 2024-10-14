# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 23:00:51 by jlievano          #+#    #+#              #
#    Updated: 2024/10/09 23:00:52 by jlievano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_lexer.a
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -g
OBJS		=	$(SRC:.c=.o)
SRC			=	ft_lexer.c

all			: 	$(NAME)

$(NAME)		:	$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY		:	clean fclean re all

