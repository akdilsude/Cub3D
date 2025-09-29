NAME	=	cub3D
SRCS	=	build_map.c		\
			direction.c 	\
			frees.c 		\
			map_control.c 	\
			parse.c  		\
			utils.c			\
			get_next_line.c \
			get_next_line_utils.c \
			main.c \

OBJS	=	$(SRCS:.c=.o)
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror
CC		=	cc
LIBFT_DIR		= 	./libft
LIBFT 			= 	$(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
		$(MAKE) -C $(LIBFT_DIR)

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(OBJS)

re: fclean all

.PHONY: all re clean fclean
