# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 16:36:40 by jlievano          #+#    #+#              #
#    Updated: 2024/09/25 16:36:41 by jlievano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror
T_DLL		=	libs/t_dll/t_dll.a
LIBFT		=	libs/libft/libft.a
OBJS		=	$(SRC:.c=.o)
SRC			=	inc/minishell.c

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(T_DLL) $(LIBFT)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(T_DLL) $(LIBFT)

$(T_DLL)	:
				$(MAKE) -C libs/t_dll/

$(LIBFT)	:
				$(MAKE) -C  libs/libft/

clean		:
				$(RM) $(OBJS)
				@make -C libs/t_dll clean
				@make -C libs/libft clean

fclean		:	clean
				$(RM) $(NAME)
				@make -C libs/t_dll fclean
				@make -C libs/libft fclean

re			:	fclean $(NAME)

.PHONY		:	all clean fclean re bonus