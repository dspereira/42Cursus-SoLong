#include "so_long.h"


/*
void make_move(t_data *data, int dir)
{
	t_pos new_pos;
	t_pos pos;
	char **map;
	
	map = data->map.map;
	pos = data->p_pos;
	new_pos = get_new_pos(pos, dir);
	if (is_valid_move(new_pos, map))
	{
		move_character(data, data->player, &(data->p_pos), dir);
		data->n_moves++;
		print_player_moves(*data);
	}
	if (is_player_collision(pos, map, COLLECTIBLE))
	{
		catch_coin(data);
		catch_coin(data);
	}
	if(is_win(*data))
		finish_game(*data);
}
*/

void finish_game(t_data data)
{
	/*mlx_destroy_image(data.win.mlx, data.imgs.coin);
	mlx_destroy_image(data.win.mlx, data.imgs.exit);
	mlx_destroy_image(data.win.mlx, data.imgs.grass);
	mlx_destroy_image(data.win.mlx, data.imgs.player);
	mlx_destroy_image(data.win.mlx, data.imgs.tree);
	mlx_destroy_window(data.win.mlx, data.win.mlx_win);*/
	free_map(data.map);
	free(data.win.mlx);
	exit(0);	
}

int is_valid_move(t_pos pos, char **map)
{
	if (is_player_collision(pos, map, TREE))
		return (0);
	return (1);
}

int is_win(t_data data)
{
	int n_coins;
	t_pos p[4];
	int i;

	n_coins = data.n_coins;
	get_player_corners(data.p_pos, p);
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

int is_lose(t_data data)
{
	int i;

	i = 0;
	while (i < data.n_enemys)
	{
		if (enemy_collision(data.p_pos, data.e_pos[i]))
		{
			printf("you lose!\n");
			return (1);
		}
		i++;
	}
	return (0);
}
