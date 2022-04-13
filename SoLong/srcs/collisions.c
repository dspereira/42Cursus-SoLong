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
