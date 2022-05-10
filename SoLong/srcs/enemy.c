#include "so_long.h"

static int is_enemy_collision(t_data data ,t_pos new, int enemy_index);

void clean_all_enemys(t_data data);
void print_enemy(t_data *data, t_img *imgs, t_pos pos, int dir);

void move_enemy1(t_data *data);
void move(t_data *data);


int enemy_move(t_data *data)
{
	static int  i = 0;   

    if (!data->n_enemys)
        return (0);
	i++;
	if (i >= 30000)
	{
        move(data);
        i = 0;
    }
    if(is_win(*data) || is_lose(*data))
		finish_game(*data);
    return (0);
}

void move(t_data *data)
{
    int i;
    int dir;
    t_pos *e_pos;
    t_pos new_pos;

    i = 0;
    clean_all_enemys(*data);
    while (i < data->n_enemys)
    {
        e_pos = &(data->e_pos[i]);
        dir = get_random_direction(*e_pos, data->p_pos);
        new_pos = get_new_pos(*e_pos, dir);
        if (is_valid_move(new_pos, data->map.map) && 
            !is_enemy_collision(*data, new_pos, i))
            *e_pos = new_pos;
        print_enemy(data, data->enemy, *e_pos, dir);
        i++;
    }
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

static int is_enemy_collision(t_data data ,t_pos new, int enemy_index)
{
    int i;

    i = 0;
    while (i < data.n_enemys)
    {
        if (i == enemy_index)
            ;
        else if (enemy_collision(new, data.e_pos[i]))
        {
            printf("Colidiu\n");
            return (1);
        }
        i++;
    }
    printf("não Colidiu\n");
    return (0);
}

void clean_all_enemys(t_data data)
{
    int i;

    i = 0;
    while (i < data.n_enemys)
    {
        clean_character(data, data.e_pos[i]);
        i++;
    }
}

void print_enemy(t_data *data, t_img *imgs, t_pos pos, int dir)
{
	static int i = 1;
	enum sprite_dir img_sprites[2];

	get_sprites(img_sprites, dir);
	print_img(data->win, pos, imgs[img_sprites[i % 2]].img);
	i++;
}
