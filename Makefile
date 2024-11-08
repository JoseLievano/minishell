# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glicciar <glicciar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 16:36:40 by jlievano          #+#    #+#              #
#    Updated: 2024/11/06 22:11:39 by glicciar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -g
LDFLAGS		=	-lreadline
T_DLL		=	libs/t_dll/t_dll.a
LIBFT		=	libs/libft/libft.a
FT_READER	=	libs/reader/ft_reader.a
FT_LEXER	=	libs/lexer/ft_lexer.a
FT_PARSER	=	libs/parser/ft_parser.a
FT_EXPANDER =	libs/expander/ft_expander.a
FT_EXECUTOR	=	libs/executor/ft_executor.a
OBJS		=	$(SRC:.c=.o)
SRC			=	src/minishell.c

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(FT_EXECUTOR) $(FT_EXPANDER) $(FT_PARSER) $(FT_LEXER) $(FT_READER) $(T_DLL) $(LIBFT)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FT_EXECUTOR) $(FT_EXPANDER) $(FT_PARSER) $(FT_LEXER) $(FT_READER) $(T_DLL) $(LIBFT) $(LDFLAGS)

$(T_DLL)	:
				$(MAKE) -C libs/t_dll/

$(LIBFT)	:
				$(MAKE) -C  libs/libft/

$(FT_READER):
				$(MAKE) -C libs/reader/

$(FT_LEXER)	:
				$(MAKE) -C libs/lexer/

$(FT_PARSER) :
				$(MAKE) -C libs/parser/

$(FT_EXPANDER) :
				$(MAKE) -C libs/expander/

$(FT_EXECUTOR)	:
				$(MAKE) -C libs/executor/

clean		:
				$(RM) $(OBJS)
				@make -C libs/t_dll clean
				@make -C libs/libft clean
				@make -C libs/reader clean
				@make -C libs/lexer clean
				@make -C libs/parser clean
				@make -C libs/expander clean
				@make -C libs/executor clean

fclean		:	clean
				$(RM) $(NAME)
				@make -C libs/t_dll fclean
				@make -C libs/libft fclean
				@make -C libs/reader fclean
				@make -C libs/lexer fclean
				@make -C libs/parser fclean
				@make -C libs/expander fclean
				@make -C libs/executor fclean

re			:	fclean $(NAME)

.PHONY		:	all clean fclean re bonus
