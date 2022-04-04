#include "so_long.h"

static void assets_init(t_data *data);
static void map_init(t_data *data);

t_data game_init(t_data *data)
{
    assets_init(data);
    map_init(data);
}

static void assets_init(t_data *data)
{
	t_imgs imgs;
	int img_width;
	int img_height;

	data->imgs.grass = mlx_xpm_file_to_image(data->win.mlx, GRASS_PATH, &img_width, &img_height);
	data->imgs.tree = mlx_xpm_file_to_image(data->win.mlx, TREE_PATH, &img_width, &img_height);
	data->imgs.player = mlx_xpm_file_to_image(data->win.mlx, PLAYER_PATH, &img_width, &img_height);
}

static void map_init(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (j < data->map.length)
		{
			if (data->map.map[i][j] == GRASS)
				mlx_put_image_to_window(data->win.mlx, data->win.mlx_win, data->imgs.grass, j * IMG_SIZE, i * IMG_SIZE);
			else if (data->map.map[i][j] == TREE)
				mlx_put_image_to_window(data->win.mlx, data->win.mlx_win, data->imgs.tree, j * IMG_SIZE, i * IMG_SIZE);
			else if (data->map.map[i][j] == PLAYER)
			{
                data->map.p.x = j * IMG_SIZE;
	            data->map.p.y = i * IMG_SIZE;
				printf("p init: x: %i y: %i \n", data->map.p.x, data->map.p.y);
				mlx_put_image_to_window(data->win.mlx, data->win.mlx_win, data->imgs.grass, j * IMG_SIZE, i * IMG_SIZE);
				mlx_put_image_to_window(data->win.mlx, data->win.mlx_win, data->imgs.player, j * IMG_SIZE, i * IMG_SIZE);
			}	
			printf("%c", data->map.map[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}