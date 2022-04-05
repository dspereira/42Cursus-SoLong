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
	t_win win;
	int w;
	int h;
	
	win = data->win;
	data->imgs.grass = mlx_xpm_file_to_image(win.mlx, GRASS_PATH, &w, &h);
	data->imgs.tree = mlx_xpm_file_to_image(win.mlx, TREE_PATH, &w, &h);
	data->imgs.player = mlx_xpm_file_to_image(win.mlx, PLAYER_PATH, &w, &h);
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
			print_image(*data, i, j);
			if (data->map.map[i][j] == PLAYER)
				update_player_pos(data, j * IMG_SIZE, i * IMG_SIZE);
			j++;
		}
		i++;
	}
}
