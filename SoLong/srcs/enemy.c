#include "so_long.h"


void clean_all_enemys(t_data data);
void print_enemy(t_data *data, t_img *imgs, t_pos pos, int dir);

void move_enemy1(t_data *data);
void move(t_data *data);
int time_counter(int n_sec);

int get_direction(t_pos e_pos, t_pos p_pos);






int enemy_move(t_data *data)
{
    if (!data->n_enemys)
        return (0);
    if(time_counter(1))
        move(data);
    if(is_win(*data) || is_lose(*data))
		finish_game(*data);
    return (0);
}

int time_counter(int n_sec)
{
	static unsigned long time_actual = 0;
	static unsigned long time_buff = 0;

	time_actual = time(NULL);
	if (time_actual - time_buff >= n_sec)
	{
		time_buff = time(NULL);
		return (1);
	}
	return (0);
}

void move(t_data *data)
{
    int i;
    int dir;
    t_pos *e_pos;
    t_pos new_pos;

    i = 0;
    clean_all_character(*data);
    while (i < data->n_enemys)
    {
        e_pos = &(data->e_pos[i]);
        dir = get_direction(*e_pos, data->p_pos);
        new_pos = get_new_pos(*e_pos, dir);
        if (is_valid_move(new_pos, data->map.map) && !is_enemy_collision(*data, new_pos, i))
            *e_pos = new_pos;
        i++;
    }
    print_all_character(*data);
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

int get_rand_direction(void)
{
    int r;

    r = get_random_num(3);
    if (r == 0)
        return (KEY_LEFT);
    else if (r == 1)
        return (KEY_RIGHT);
    else if (r == 2)
        return (KEY_UP);
    else if (r == 3)
        return (KEY_DOWN);  
}

int get_direction(t_pos e_pos, t_pos p_pos)
{
    int r;
    int dir;

    r = get_random_num(2);
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
        dir = get_rand_direction();
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
