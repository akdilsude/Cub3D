NAME			=	cub3D

SRCS_DIR		=	srcs
INC_DIR			=	inc

SRCS_FILES		=	control_identifier.c	\
					frees.c					\
					get_next_line.c			\
					check_color.c 			\
					handle_direct.c 		\
					main.c					\
					open_map.c 				\
					parse_path.c  			\
					process_map.c 			\
					process_map2.c 			\
					process_map3.c 			\
					process_map4.c 			\
					utils.c					\
					init.c					\
					utils2.c				\
					color_and_draw.c		\
					raycasting.c			\
					movement.c				\
					vertical_line.c			\
					flood_fill.c			\

SRCS            =   $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
OBJS			=	$(SRCS:.c=.o)

RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MINILIBX_DIR)
CC				=	cc

LIBFT_DIR		= 	./libft
LIBFT 			= 	$(LIBFT_DIR)/libft.a
MINILIBX_DIR	=	minilibx-linux
MINILIBX 		=	$(MINILIBX_DIR)/libmlx.a
LFLAGS 			=	-Lminilibx-linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm


all: $(LIBFT) $(MINILIBX) $(NAME)

$(MINILIBX):
	@make -C $(MINILIBX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(LFLAGS) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean: 
	$(RM) $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(OBJS)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(MINILIBX_DIR) clean

re: fclean all

.PHONY: all re clean fclean
