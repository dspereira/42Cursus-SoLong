#include "so_long.h"

int get_random_num(int max_value)
{
    int r;

    srand(time(NULL));
	r = rand() % (max_value + 1);
    return (r);
}

t_pos get_new_pos(t_pos pos, int dir)
{
	if (dir == KEY_UP)
		pos.y -= MOVE_RANGE;
	else if (dir == KEY_DOWN)
		pos.y += MOVE_RANGE;
	else if (dir == KEY_RIGHT)
		pos.x += MOVE_RANGE;
	else if (dir == KEY_LEFT) 
		pos.x -= MOVE_RANGE;
    return (pos);
}

int get_random_direction(t_pos e_pos, t_pos p_pos)
{
    int r;
    int dir;

    r = get_random_num(5);
    if (r == 0)
    {
        if (p_pos.x < e_pos.x)
            dir = KEY_LEFT;
        else
            dir = KEY_RIGHT;
    }
    else if(r == 1)
    {
        if (p_pos.y < e_pos.y)
            dir = KEY_UP;
        else
            dir = KEY_DOWN;
    }
    else if (r >= 2)
    {
        r = get_random_num(3);
        if (r == 0)
            dir = KEY_LEFT;
        else if (r == 1)
            dir = KEY_RIGHT;
        else if (r == 2)
            dir = KEY_UP;
        else if (r == 3)
            dir = KEY_DOWN;
    }
    return (dir);
}

int make_move_2(t_data *data, int dir)
{
	t_pos new_pos;

    new_pos = get_new_pos(data->e_pos, dir);
	if (is_valid_move(new_pos, data->map.map))
	{
		move_character_novo(data, data->enemy, &(data->e_pos), dir);
		return (1);
	}
	return (0);
}

int enemy_call1(t_data *data)
{
	static int i = 0;
    int dir;
    t_pos new_pos;

	i++;
	if (i >= 10000)
	{
        dir = get_random_direction(data->e_pos, data->p_pos);
        if (make_move_2(data, dir));
            i = 0;
    }
    return (0);
}