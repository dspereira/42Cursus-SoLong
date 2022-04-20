#include "so_long.h"

void update_player_pos(t_data *data, t_pos pos)
{
	data->p_pos.x = pos.x;
	data->p_pos.y = pos.y;
}

void move_player(t_data *data, t_pos p)
{
	void *p_img;

	clean_character(*data, data->p_pos);
	update_player_pos(data, p);
	print_img(*data, data->p_pos, PLAYER);
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

	clean_character(*data, data->p_pos);
	update_player_pos(data, p);
	get_sprites_player(i_img, dir);
	print_img_by_index(*data, p, i_img[i % 2]);
	i++;
}
