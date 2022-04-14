#include "so_long.h"

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

void clean_player(t_data data)
{
	t_pos p[4];
	int i;
	int j;
	int a;

	get_player_corners(data.map.p, p);
	a = 0;
	while(a < 4)
	{
		get_map_pos(p[a], &i, &j);
		print_img_from_map(data, i, j);
		a++;
	}
}
