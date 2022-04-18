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

void get_sprites_player(enum Index_image *i_img, int dir)
{
	if (dir == KEY_UP)
	{
		i_img[0] = P_UP_1;
		i_img[1] = P_UP_2;
	}
	if (dir == KEY_DOWN)
	{
		i_img[0] = P_DOWN_1;
		i_img[1] = P_DOWN_2;
	}
	if (dir == KEY_LEFT)
	{
		i_img[0] = P_LEFT_1;
		i_img[1] = P_LEFT_2;
	}
	if (dir == KEY_RIGHT)
	{
		i_img[0] = P_RIGHT_1;
		i_img[1] = P_RIGHT_2;
	}
}

void move_player1(t_data *data, t_pos p, int dir)
{
	static int i = 1;
	void *p_img;
	enum Index_image i_img[2];

	clean_player(*data);
	update_player_pos(data, p);
	get_sprites_player(i_img, dir);
	print_img_by_index(*data, p, i_img[i % 2]);
	i++;
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
