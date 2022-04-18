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

