#include "so_long.h"

int	key_down(int keycode, t_data *data)
{
	if (keycode == KEY_DOWN || keycode == KEY_UP
		|| keycode == KEY_LEFT || keycode == KEY_RIGHT)
		player_move(data, keycode);
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
	return (0);
}

int enemy_call(t_data *data)
{
	static int i = 0;
    int dir;
    t_pos new_pos;
    int n_enemys;

    n_enemys = data->n_enemys - 1;
	i++;
	if (i >= 8000)
	{
        while (n_enemys >= 0)
        {
            dir = get_random_direction(data->e_pos[n_enemys], data->p_pos);
            make_move_2(data, &(data->e_pos[n_enemys]), dir);
            n_enemys--;
        }
        i = 0;
    }
    return (0);
}