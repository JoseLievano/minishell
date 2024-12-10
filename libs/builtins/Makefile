
NAME	=	ft_built_ins.a
CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror -g
OBJS	=	$(SRC:.c=.o)
SRC		=	ft_built_ins.c

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	clean fclean re all