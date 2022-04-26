#include "so_long.h"

int get_random_num(int max_value)
{
    static int i = 0;
    int r;

    i++;
    srand(time(NULL) + i);
	r = rand() % (max_value + 1);
    return (r);
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

int make_move_2(t_data *data, t_pos *e_pos, int dir)
{
	t_pos new_pos;

    new_pos = get_new_pos(*e_pos, dir);
	if (is_valid_move(new_pos, data->map.map))
	{
		move_character_novo(data, data->enemy, e_pos, dir);
		return (1);
	}
	return (0);
}

int enemy_call1(t_data *data)
{
	static int i = 0;
    int dir;
    t_pos new_pos;
    int n_enemys;

    n_enemys = data->n_enemys - 1;
	i++;
	if (i >= 10000)
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

int get_number_enemys(t_map map)
{
    int i;
    int j;
    int n;

    n = 0;
    i = 0;
    while (i < map.height)
    {
        j = 0;
        while(j < map.length)
        {
            if (map.map[i][j] == ENEMY)
                n++;
            j++;
        }
        i++;
    }
    return (n);
}
