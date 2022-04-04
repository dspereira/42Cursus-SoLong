#include "so_long.h"


int is_valid_move(t_map map, int x, int y)
{
	int i;
	int j;
	int a;

	map.p.x += x;
	map.p.y += y;
	

	if (x != 0)
	{
		if (x < 0)
		{
			j = map.p.x / IMG_SIZE;
			i = map.p.y / IMG_SIZE;
			a = (map.p.y + 58) / IMG_SIZE;
			if (map.map[i][j] == '1' || map.map[a][j] == '1')
				return (0);
		}
		else if (x > 0)
		{
			j = (map.p.x + 58) / IMG_SIZE;
			i = map.p.y / IMG_SIZE;
			a = (map.p.y + 58) / IMG_SIZE;
			if (map.map[i][j] == '1' || map.map[a][j] == '1')
				return (0);

		}
	}
	else 
	{
		if (y < 0)
		{
			j = map.p.x / IMG_SIZE;
			i = map.p.y / IMG_SIZE;
			a = (map.p.x + 58) / IMG_SIZE;
			if (map.map[i][j] == '1' || map.map[i][a] == '1')
				return (0);
		}
		else if (y > 0)
		{
			j = map.p.x / IMG_SIZE;
			i = (map.p.y + 58) / IMG_SIZE;
			a = (map.p.x + 58) / IMG_SIZE;
			if (map.map[i][j] == '1' || map.map[i][a] == '1')
				return (0);
		}

	}
	printf("range de movimento: x: %i  y: %i\n", map.p.x, map.p.y);
	return (1);
}

