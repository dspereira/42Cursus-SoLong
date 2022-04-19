#include "so_long.h"

/*
	Cheks for single point colision
*/
int is_collision(t_pos pos, char **map, char c)
{
	int i;
	int j;

	get_map_pos(pos, &i, &j);
	if (map[i][j] == c)
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
			return (1);
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
	if ((e[0].x + 1 > p[0].x && e[0].x - 1 < p[1].x)
		|| (e[1].x + 1 > p[0].x && e[1].x - 1 < p[1].x))
		i++;
	if ((e[1].y + 1 > p[1].y &&  e[1].y + 1 < p[2].y)
		|| (e[2].y - 1 > p[1].y && e[2].y - 1 < p[2].y))
		i++;
	if (i > 1)
		return (1);
	return (0);
}
