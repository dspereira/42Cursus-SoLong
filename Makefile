
NAME		= 	so_long

OBJ_DIR		= obj/
SRC_DIR		= srcs/

GNL_OBJ_DIR	= obj/get_next_line/

SOLONG		= 	$(wildcard srcs/*.c)
GNL			= 	$(wildcard srcs/get_next_line/*.c)

SRCS 		= 	$(SOLONG) \
				$(GNL)

OBJS		=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -I./includes
MLX_FLAGS_C		= -O3 -Imlx_linux
MLX_FLAGS_L		= -O3 -Imlx_linux -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
RM				= rm -rf

MAKE_MLX		= make -C mlx_linux/
CLEAN_MLX 		= make clean -C mlx_linux/


$(OBJ_DIR)%.o: $(SRC_DIR)%.c 
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(GNL_OBJ_DIR)
	$(CC) $(CFLAGS) $(MLX_FLAGS_C) -c $< -o $@

all : $(NAME)

$(NAME): $(OBJS)
	$(MAKE_MLX)
	$(CC) $(OBJS) $(CFLAGS) $(MLX_FLAGS_L) -o $(NAME)

clean:
	$(CLEAN_MLX)
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
