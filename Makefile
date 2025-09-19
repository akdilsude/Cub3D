NAME = cub3D

LIBFT = libft/libft.a
SRCS = main.c
OBJS = $(SRCS:.c=.o)
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
CC = cc

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(OBJS) -o $(NAME)

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(OBJS)

re: fclean all

.PHONY: all re clean fclean
