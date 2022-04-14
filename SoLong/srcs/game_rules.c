#include "so_long.h"

static int is_valid_move(t_pos pos, char **map);
static int is_win(t_data data);

void make_move(t_data *data, int x_offset, int y_offset)
{
	t_pos p;
	t_map map;

	map = data->map;
	p.x = map.p.x + x_offset;
	p.y = map.p.y + y_offset;
	if (is_valid_move(p, map.map))
		move_player(data, p);
	if (is_player_collision(map.p, map.map, COLLECTIBLE))
	{
		catch_coin(data);
		catch_coin(data);
	}
	if(is_win(*data))
		finish_game(*data);
}

void finish_game(t_data data)
{
	mlx_destroy_image(data.win.mlx, data.imgs.coin);
	mlx_destroy_image(data.win.mlx, data.imgs.exit);
	mlx_destroy_image(data.win.mlx, data.imgs.grass);
	mlx_destroy_image(data.win.mlx, data.imgs.player);
	mlx_destroy_image(data.win.mlx, data.imgs.tree);
	mlx_destroy_window(data.win.mlx, data.win.mlx_win);
	free_map(data.map);
	exit(0);	
}

static int is_valid_move(t_pos pos, char **map)
{
	if (is_player_collision(pos, map, TREE))
		return (0);
	return (1);
}

static int is_win(t_data data)
{
	int n_coins;
	t_pos p[4];
	int i;

	n_coins = data.map.n_collect;
	get_player_corners(data.map.p, p);
	i = 0;
	while (i < 4)
	{
		if (is_collision(p[i], data.map.map, EXIT))
		{
			if (n_coins == 0)
				return (1);
		}
		i++;
	}	
	return (0);
}
