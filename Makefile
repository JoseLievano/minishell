# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glicciar <glicciar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 16:36:40 by jlievano          #+#    #+#              #
#    Updated: 2024/11/13 18:42:13 by jlievano         ###   ########.fr        #
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
FT_BUILTINS	=	libs/builtins/ft_built_ins.a
OBJS		=	$(SRC:.c=.o)
SRC_DIR		=	src/
SRC_FILES	=	minishell.c ft_get_env_var.c ft_set_shell_path.c \
				ft_execution_mode.c ft_parse_args.c ft_noninteractive_shell.c \
				ft_interactive_shell.c ft_clean_minishell.c ft_signals.c
SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(FT_EXECUTOR) $(FT_BUILTINS) $(FT_EXPANDER) $(FT_PARSER) $(FT_LEXER) $(FT_READER) $(T_DLL) $(LIBFT)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FT_EXECUTOR) $(FT_BUILTINS) $(FT_EXPANDER) $(FT_PARSER) $(FT_LEXER) $(FT_READER) $(T_DLL) $(LIBFT) $(LDFLAGS)

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

$(FT_BUILTINS)	:
				$(MAKE) -C libs/builtins

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
				@make -C libs/builtins clean

fclean		:	clean
				$(RM) $(NAME)
				@make -C libs/t_dll fclean
				@make -C libs/libft fclean
				@make -C libs/reader fclean
				@make -C libs/lexer fclean
				@make -C libs/parser fclean
				@make -C libs/expander fclean
				@make -C libs/executor fclean
				@make -C libs/builtins fclean

re			:	fclean $(NAME)

valgrind	= 	valgrind --suppressions=valgrind.supp --leak-check=full --show-leak-kinds=all

val1		:
				$(valgrind) ./minishell 1

val2		:
				$(valgrind) ./minishell 2

val3		:
				$(valgrind) ./minishell 3

val4		:
				$(valgrind) ./minishell 4

val5		:
				$(valgrind) ./minishell 5

.PHONY		:	all clean fclean re bonus valgrind val1
