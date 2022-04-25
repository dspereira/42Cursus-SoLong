#include "so_long.h"

void get_sprites(enum sprite_dir *i_img, int dir)
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

void update_position(t_pos *pos, int dir)
{
	if (dir == KEY_UP)
		pos->y -= MOVE_RANGE;
	else if (dir == KEY_DOWN)
		pos->y += MOVE_RANGE;
	else if (dir == KEY_RIGHT)
		pos->x += MOVE_RANGE;
	else if (dir == KEY_LEFT) 
		pos->x -= MOVE_RANGE;
}

void move_character_novo(t_data *data, t_img *imgs, t_pos *pos, int dir)
{
	static int i = 1;
	enum sprite_dir img_sprites[2];

	get_sprites(img_sprites, dir);
	clean_character(*data, *pos);
	update_position(pos, dir);
	print_img(data->win, *pos, imgs[img_sprites[i % 2]].img);
	i++;
}