NAME	=	cub3D
SRCS	=	control_identifier.c \
			frees.c 		\
			get_next_line.c \
			handle_colors.c 	\
			handle_direct.c 	\
			main.c \
			open_map.c 		\
			parse_path.c  		\
			process_map.c 		\
			process_map2.c 		\
			process_map3.c 		\
			utils.c			\


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
	@make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(OBJS)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all re clean fclean
