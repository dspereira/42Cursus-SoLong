#include "so_long.h"

static void clean_character(t_data data, t_pos pos);
static void get_sprites(enum sprite_dir *i_img, int dir);

void move_character(t_data *data, t_img *imgs, t_pos *pos, int dir)
{
	static int i = 1;
	enum sprite_dir img_sprites[2];

	get_sprites(img_sprites, dir);
	clean_character(*data, *pos);
	*pos = get_new_pos(*pos, dir);
	print_img(data->win, *pos, imgs[img_sprites[i % 2]].img);
	i++;
}

static void clean_character(t_data data, t_pos pos)
{
	t_pos a_pos[4];
	t_map_pos m_pos;
	int i;

	get_player_corners(pos, a_pos);
	i = 0;
	while(i < 4)
	{
		m_pos = get_map_pos(a_pos[i]);
		print_img_from_map(data, m_pos.i, m_pos.j);
		i++;
	}
}

static void get_sprites(enum sprite_dir *i_img, int dir)
{
	if (dir == KEY_UP)
	{
		i_img[0] = UP_1;
		i_img[1] = UP_2;
	}
	if (dir == KEY_DOWN)
	{
		i_img[0] = DOWN_1;
		i_img[1] = DOWN_2;
	}
	if (dir == KEY_LEFT)
	{
		i_img[0] = LEFT_1;
		i_img[1] = LEFT_2;
	}
	if (dir == KEY_RIGHT)
	{
		i_img[0] = RIGHT_1;
		i_img[1] = RIGHT_2;
	}
}
