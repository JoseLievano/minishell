# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 19:40:47 by jlievano          #+#    #+#              #
#    Updated: 2024/11/08 19:40:48 by jlievano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_executor.a
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -g
OBJS		=	$(SRC:.c=.o)
ENVS_DIR	=	envs/
ENVS_FILES	=	ft_find_env.c ft_find_cmd_path.c ft_envs_to_array.c
REDIR_DIR	=	redirections/
REDIR_FILES	=	ft_append.c ft_heredoc.c ft_input.c ft_output.c \
				ft_process_redirections.c ft_executable_redirections.c
PIPE_DIR	=	pipes/
PIPE_FILES	=	ft_pipes_config.c ft_setup_piped_cmd_position.c
ERR_DIR		=	error/
ERR_FILES	=	ft_execute_error.c
SRC			=	$(addprefix $(ENVS_DIR), $(ENVS_FILES)) \
				$(addprefix $(REDIR_DIR), $(REDIR_FILES)) \
				$(addprefix $(ERR_DIR), $(ERR_FILES)) \
				$(addprefix $(PIPE_DIR), $(PIPE_FILES)) \
				ft_executor.c ft_execute_cmd.c

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY		:	clean fclean re all
