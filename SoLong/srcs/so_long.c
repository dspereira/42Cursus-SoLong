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
	printf("poiter to img: |%p|\n", imgs.grass);
	imgs.tree = mlx_xpm_file_to_image(mlx, TREE_PATH, &img_width, &img_height);
	printf("TREE: size: %i x %i\n", img_width, img_height);
	imgs.player = mlx_xpm_file_to_image(mlx, PLAYER_PATH, &img_width, &img_height);
	printf("TREE: size: %i x %i\n", img_width, img_height);
	return (imgs);
}


void init_map(t_map map, t_imgs imgs, void	*mlx, void	*mlx_win)
{
	int i;
	int j;

	printf("poiter to img: |%p|\n", imgs.grass);
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.length)
		{
			if (map.map[i][j] == GRASS)
				mlx_put_image_to_window(mlx, mlx_win, imgs.grass, j * IMG_SIZE, i * IMG_SIZE);
			else if (map.map[i][j] == TREE)
				mlx_put_image_to_window(mlx, mlx_win, imgs.tree, j * IMG_SIZE, i * IMG_SIZE);
			else if (map.map[i][j] == PLAYER)
			{
				mlx_put_image_to_window(mlx, mlx_win, imgs.grass, j * IMG_SIZE, i * IMG_SIZE);
				mlx_put_image_to_window(mlx, mlx_win, imgs.player, j * IMG_SIZE, i * IMG_SIZE);
			}	
			printf("%c", map.map[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}

int main(int argc, char **argv)
{
	t_map 	map;
	t_imgs	imgs;
	void	*mlx;
	void	*mlx_win;

	if (argc != 2)
	{
		printf("Wrong parmeters: You have to indicate the path of map\n");
		return (0);
	}
	map = get_map(argv[1]);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, map.length * IMG_SIZE, map.height * IMG_SIZE, "SoLong");	
	imgs = init_assets(mlx);
	init_map(map, imgs, mlx, mlx_win);
	mlx_loop(mlx);
	return (0);
}
