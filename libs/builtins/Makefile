
NAME	=	ft_built_ins.a
CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror -g
OBJS	=	$(SRC:.c=.o)
SRC		=	ft_built_ins.c ft_echo.c ft_cd.c ft_export.c ft_export_utils.c ft_pwd.c ft_env.c ft_unset.c ft_exit.c

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	clean fclean re all