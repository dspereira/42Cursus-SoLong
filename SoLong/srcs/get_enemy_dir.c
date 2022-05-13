#include "so_long.h"

static int get_random_num(int max_value);
static int get_rand_direction(void);

int get_enemy_dir(t_pos e_pos, t_pos p_pos)
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

static int get_random_num(int max_value)
{
    static int i = 0;
    int r;

    srand(time(NULL) + i);
	r = rand() % (max_value + 1);
    i++;
    return (r);
}

static int get_rand_direction(void)
{
    int r;

    r = get_random_num(3);
    if (r == 0)
        return (KEY_LEFT);
    else if (r == 1)
        return (KEY_RIGHT);
    else if (r == 2)
        return (KEY_UP);
    else
        return (KEY_DOWN);  
}
