#include "so_long.h"

int	key_control(int keycode, t_data *data)
{
	if (keycode == KEY_DOWN || keycode == KEY_UP
		|| keycode == KEY_LEFT || keycode == KEY_RIGHT)
		make_move(data, keycode);
	return (0);
}

int key_up(int keycode, t_data *data)
{
	void *img;

	img = 0;
	if (keycode == KEY_UP)
		img = data->player[UP_0].img;
	else if (keycode == KEY_DOWN)
		img = data->player[DOWN_0].img;
	else if (keycode == KEY_LEFT)
		img = data->player[LEFT_0].img;
	else if (keycode == KEY_RIGHT)
		img = data->player[RIGHT_0].img;
	if (img)
		print_img(data->win, data->p_pos, img);
	return (0);
}