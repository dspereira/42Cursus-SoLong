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
	data->imgs.coin = mlx_xpm_file_to_image(win.mlx, COIN_PATH, &w, &h);
}

static void map_init(t_data *data)
{
	t_pos pos;
	t_map map;
	int i;
	int j;
	
	map = data->map;
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.length)
		{
			print_image(*data, i, j);
			if (map.map[i][j] == PLAYER)
				update_player_pos(data, *get_win_pos(i, j, &pos));
			j++;
		}
		i++;
	}
}
