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
FT_READER	=	libs/reader/ft_reader.a
OBJS		=	$(SRC:.c=.o)
SRC			=	src/minishell.c

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(T_DLL) $(LIBFT) $(FT_READER)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(T_DLL) $(LIBFT) $(FT_READER)

$(T_DLL)	:
				$(MAKE) -C libs/t_dll/

$(LIBFT)	:
				$(MAKE) -C  libs/libft/

$(FT_READER):
				$(MAKE) -C libs/reader/

clean		:
				$(RM) $(OBJS)
				@make -C libs/t_dll clean
				@make -C libs/libft clean
				@make -C libs/reader clean

fclean		:	clean
				$(RM) $(NAME)
				@make -C libs/t_dll fclean
				@make -C libs/libft fclean
				@make -C libs/reader fclean

re			:	fclean $(NAME)

.PHONY		:	all clean fclean re bonus