#include "so_long.h"

/*
	Cheks for single point colision
*/
int is_collision(t_pos pos, char **map, char c)
{
	t_map_pos m_pos;

	m_pos = get_map_pos(pos);
	if (map[m_pos.i][m_pos.j] == c)
		return (1);
	return (0);
}

/*
	Cheks for colisions in every cornor of player image
*/
int is_player_collision(t_pos start_p, char **map, char c)
{
	t_pos pos[4];
	int i;

	get_player_corners(start_p, pos);
	i = 0;
	while (i < 4)
	{
		if (is_collision(pos[i], map, c))
		{
			printf("detetou colisão \n");
			return (1);
		}
		i++;		
	}
	return (0);
}

int enemy_collision(t_pos player, t_pos enemy)
{
	t_pos e[4];
	t_pos p[4];
	int i;

	i = 0;
	get_player_corners(player, p);
	get_player_corners(enemy, e);
	if ((e[0].x >= p[0].x && e[0].x <= p[1].x)
		|| (e[1].x >= p[0].x && e[1].x <= p[1].x))
		i++;
	if ((e[1].y >= p[1].y &&  e[1].y <= p[2].y)
		|| (e[2].y >= p[1].y && e[2].y <= p[2].y))
		i++;
	if (i > 1)
		return (1);
	return (0);
}

int is_enemy_collision(t_data data ,t_pos new, int enemy_index)
{
    int i;

    i = 0;
    while (i < data.n_enemys)
    {
        if (i != enemy_index && enemy_collision(new, data.e_pos[i]))
            return (1);
        i++;
    }
    return (0);
}