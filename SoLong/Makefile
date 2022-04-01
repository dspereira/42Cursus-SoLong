NAME		= 	solong

SOLONG		= 	$(wildcard srcs/*.c)
GNL			= 	$(wildcard get_next_line/*.c)

SRCS 		= 	$(SOLONG) \
				$(GNL)

OBJS		= 	$(SRCS:.c=.o)

CC				= gcc
CFLAGS			= -I./includes
MLX_MACOS		= -Imlx
MLX_MACOS1		= -lmlx -framework OpenGL -framework AppKit
MLX_F_LINUX		= -Imlx_linux -O3
MLX_F_LINUX1	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
RM				= rm -f

%.o: %.c
	$(CC) $(CFLAGS) $(MLX_MACOS) -c $< -o $@

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MLX_MACOS1) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
