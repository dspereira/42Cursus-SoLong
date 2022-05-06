#include "so_long.h"

int move_enemy(t_data *data)
{
	static int  i = 0;
    int         j;
    int         dir;
    t_pos       *e_pos;

	i++;
	if (i >= 10000)
	{
        j = 0;
        while (j < data->n_enemys)
        {
            e_pos = &(data->e_pos[j]);
            dir = get_random_direction(*e_pos, data->p_pos);
            if (is_valid_move(get_new_pos(*e_pos, dir), data->map.map))
		        move_character(data, data->enemy, e_pos, dir);
            j++;
        }
        i = 0;
    }
    return (0);
}

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
