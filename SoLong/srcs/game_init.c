#include "so_long.h"

static void assets_init(t_data *data);
static void map_init(t_data *data);

t_data game_init(t_data *data)
{
    assets_init(data);
    map_init(data);
	return (*data);
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
	data->imgs.coin = mlx_xpm_file_to_image(win.mlx, COIN_PATH, &w, &h);
	data->imgs.exit = mlx_xpm_file_to_image(win.mlx, EXIT_PATH, &w, &h);

	data->imgs.player = mlx_xpm_file_to_image(win.mlx, P_UP_0_PATH, &w, &h);
	//data->imgs.player[1] = mlx_xpm_file_to_image(win.mlx, P_DOWN_1_PATH, &w, &h);
	//data->imgs.player[2] = mlx_xpm_file_to_image(win.mlx, P_DOWN_2_PATH, &w, &h);
}

static void map_init(t_data *data)
{
	t_pos pos;
	t_map map;
	int i;
	int j;
	int collect;
	
	map = data->map;
	collect = 0;
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.length)
		{
			print_img_from_map(*data, i, j);
			if (map.map[i][j] == PLAYER)
			{
				update_player_pos(data, *get_window_pos(i, j, &pos));
				map.map[i][j] = GRASS;
			}
			if (map.map[i][j] == COLLECTIBLE)
				collect++;
			j++;
		}
		i++;
	}
	data->map.n_collect = collect;
}
