#include "so_long.h"

int is_valid_move(t_pos pos, char **map)
{
	if (is_player_collision(pos, map, TREE))
		return (0);
	return (1);
}

void update_player_pos(t_data *data, t_pos pos)
{
	data->map.p.x = pos.x;
	data->map.p.y = pos.y;
}

void move_player(t_data *data, t_pos p)
{
	void *p_img;

	clean_player(*data);
	update_player_pos(data, p);
	print_img(*data, data->map.p, PLAYER);
}

int is_player_win(t_data data)
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
