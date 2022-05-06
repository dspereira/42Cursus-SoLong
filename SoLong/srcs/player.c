#include "so_long.h"

// criar função de update numero de jogadas

int	player_start_move(int keycode, t_data *data)
{
	if (keycode == KEY_DOWN || keycode == KEY_UP
		|| keycode == KEY_LEFT || keycode == KEY_RIGHT)
		player_move(data, keycode);
	return (0);
}

int player_stop_move(int keycode, t_data *data)
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

void player_move(t_data *data, int dir)
{
	t_pos new_pos;
	t_pos pos;
	char **map;
	
	map = data->map.map;
	pos = data->p_pos;
	new_pos = get_new_pos(pos, dir);
	if (is_valid_move(new_pos, map))
	{
		move_character(data, data->player, &(data->p_pos), dir);
		data->n_moves++;
		print_player_moves(*data);
	}
	if (is_player_collision(pos, map, COLLECTIBLE))
	{
		catch_coin(data);
		catch_coin(data);
	}
	if(is_win(*data))
		finish_game(*data);
}