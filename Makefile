
NAME		= 	so_long

SOLONG		= 	$(wildcard srcs/*.c)
GNL			= 	$(wildcard get_next_line/*.c)

SRCS 		= 	$(SOLONG) \
				$(GNL)

OBJS		= 	$(SRCS:.c=.o)

CC				= gcc
#CFLAGS			= -Wall -Wextra -Werror -I./includes
CFLAGS			= -I./includes
MLX_FLAGS_C		= -O3 -Imlx_linux
MLX_FLAGS_L		= -O3 -Imlx_linux -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
RM				= rm -f
MAKE_MLX	= make -C mlx_linux/
CLEAN_MLX 	= make clean -C mlx_linux/

%.o: %.c
	$(CC) $(CFLAGS) $(MLX_FLAGS_C) -c $< -o $@

all : $(NAME)

$(NAME): $(OBJS)
	$(MAKE_MLX)
	$(CC) $(OBJS) $(CFLAGS) $(MLX_FLAGS_L) -o $(NAME)

clean:
	$(CLEAN_MLX)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
