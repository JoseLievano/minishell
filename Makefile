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
CFLAGS		=	-Wall -Wextra -Werror -g
LDFLAGS		=	-lreadline
T_DLL		=	libs/t_dll/t_dll.a
LIBFT		=	libs/libft/libft.a
FT_READER	=	libs/reader/ft_reader.a
FT_LEXER	=	libs/lexer/ft_lexer.a
FT_PARSER	=	libs/parser/ft_parser.a
OBJS		=	$(SRC:.c=.o)
SRC			=	src/minishell.c

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(FT_PARSER) $(FT_LEXER) $(FT_READER) $(T_DLL) $(LIBFT)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FT_PARSER) $(FT_LEXER) $(FT_READER) $(T_DLL) $(LIBFT) $(LDFLAGS)

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

clean		:
				$(RM) $(OBJS)
				@make -C libs/t_dll clean
				@make -C libs/libft clean
				@make -C libs/reader clean
				@make -C libs/lexer clean
				@make -C libs/parser clean

fclean		:	clean
				$(RM) $(NAME)
				@make -C libs/t_dll fclean
				@make -C libs/libft fclean
				@make -C libs/reader fclean
				@make -C libs/lexer fclean
				@make -C libs/parser fclean

re			:	fclean $(NAME)

.PHONY		:	all clean fclean re bonus