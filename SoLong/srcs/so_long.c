#include "so_long.h"

// função de teste durante o desenvolvimento
void print_map(t_map map)
{
	int i; 
	
	i = 0;
	printf("mapa h: %i\n", map.height);
	printf("mapa l: %i\n", map.length);
	while(i < map.height)
	{
		if (map.map[i])
			printf("%s\n", map.map[i]);
		else 
			printf("\n");
		i++;
	}
}

t_imgs init_assets(void *mlx)
{
	t_imgs imgs;
	int img_width;
	int img_height;

	imgs.grass = mlx_xpm_file_to_image(mlx, GRASS_PATH, &img_width, &img_height);
	printf("GRASS: size: %i x %i\n", img_width, img_height);
	imgs.tree = mlx_xpm_file_to_image(mlx, TREE_PATH, &img_width, &img_height);
	printf("TREE: size: %i x %i\n", img_width, img_height);
	imgs.player = mlx_xpm_file_to_image(mlx, PLAYER_PATH, &img_width, &img_height);
	printf("TREE: size: %i x %i\n", img_width, img_height);
	return (imgs);
}


void init_map(t_map map, t_imgs imgs, t_win	win)
{
	int i;
	int j;

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.length)
		{
			if (map.map[i][j] == GRASS)
				mlx_put_image_to_window(win.mlx, win.mlx_win, imgs.grass, j * IMG_SIZE, i * IMG_SIZE);
			else if (map.map[i][j] == TREE)
				mlx_put_image_to_window(win.mlx, win.mlx_win, imgs.tree, j * IMG_SIZE, i * IMG_SIZE);
			else if (map.map[i][j] == PLAYER)
			{
				mlx_put_image_to_window(win.mlx, win.mlx_win, imgs.grass, j * IMG_SIZE, i * IMG_SIZE);
				mlx_put_image_to_window(win.mlx, win.mlx_win, imgs.player, j * IMG_SIZE, i * IMG_SIZE);
			}	
			printf("%c", map.map[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}


void up(t_data *data)
{
	//mlx_put_image_to_window(data->win.mlx, data->win.mlx_win,data->imgs.player, 0 * IMG_SIZE, 0 * IMG_SIZE);
	printf("cima\n");
}

void down(void)
{
	printf("baixo\n");
}

void left(void)
{
	printf("esquerda\n");
}

void right(void)
{
	printf("direita\n");
}

int	key_press(int keycode, t_data *data)
{
	printf("keycode: %i\n", keycode);

	if (keycode == KEY_UP)
		up(data);
	else if (keycode == KEY_DOWN)
		down();
	else if (keycode == KEY_LEFT)
		left();
	else if (keycode == KEY_RIGHT)
		right();
	return (34);
}

int main(int argc, char **argv)
{
	t_map 	map;
	t_imgs	imgs;
	t_win	win;
	t_data	data;

	if (argc != 2)
	{
		printf("Wrong parmeters: You have to indicate the path of map\n");
		return (0);
	}
	map = get_map(argv[1]);
	win.mlx = mlx_init();
	win.mlx_win = mlx_new_window(win.mlx, map.length * IMG_SIZE, map.height * IMG_SIZE, "SoLong");	
	imgs = init_assets(win.mlx);
	init_map(map, imgs, win);
	data.imgs = imgs;
	data.map = map;
	data.win = win;
	mlx_hook(win.mlx_win, ON_KEYDOWN, 1L<<0, key_press, &data);
	mlx_loop(win.mlx);
	return (0);
}
