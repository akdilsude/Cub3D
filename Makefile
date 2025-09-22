NAME	=	cub3D
SRCS	=	build_map.c		\
			direction.c 	\
			frees.c 		\
			map_control.c 	\
			parse.c  		\
			utils.c			\

OBJS	=	$(SRCS:.c=.o)
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror
CC		=	cc
LIBFT	=	libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(OBJS) -o $(NAME)

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(OBJS)

re: fclean all

.PHONY: all re clean fclean
