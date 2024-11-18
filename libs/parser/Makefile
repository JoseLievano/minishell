# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 11:59:10 by jlievano          #+#    #+#              #
#    Updated: 2024/10/22 11:59:11 by jlievano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_parser.a
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -g
OBJS		=	$(SRC:.c=.o)
SRC			=	parser_to_str.c ft_parser.c ft_syntax_check.c \
				ft_red_ver.c ft_cmdt_type.c ft_get_cmdt.c ft_get_cmd.c \
				ft_parser_utils.c ft_redirection.c ft_clean_cmdt.c \
				ft_sort_redirections.c ft_get_pipes_cmd.c

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY		:	clean fclean re all
