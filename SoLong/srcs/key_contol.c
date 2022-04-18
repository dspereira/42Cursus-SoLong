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
	t_pos pos;

	pos = data->map.p;
	if (keycode == KEY_UP)
		print_img_by_index(*data, pos, P_UP_0);
	else if (keycode == KEY_DOWN)
		print_img_by_index(*data, pos, P_DOWN_0);
	else if (keycode == KEY_LEFT)
		print_img_by_index(*data, pos, P_LEFT_0);
	else if (keycode == KEY_RIGHT)
		print_img_by_index(*data, pos, P_RIGHT_0);
}
