#include "so_long.h"

int	key_control(int keycode, t_data *data)
{
	if (keycode == KEY_UP)
		make_move(data, 0, -MOVE_RANGE, keycode);
	else if (keycode == KEY_DOWN)
		make_move(data, 0, MOVE_RANGE, keycode);
	else if (keycode == KEY_LEFT)
		make_move(data, -MOVE_RANGE, 0, keycode);
	else if (keycode == KEY_RIGHT)
		make_move(data, MOVE_RANGE, 0, keycode);
	else if (keycode == KEY_ESC)
		finish_game(*data);
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
	
}