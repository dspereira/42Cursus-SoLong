#include "so_long.h"

static int map_is_rectangle(t_map map);
static int map_have_walls(t_map map);
static void search_elemnts(t_map map, int *c, int *e, int *p);
static int map_have_all_elements(t_map map);

int map_validation(t_map map)
{
    if (!map_is_rectangle(map) || !map_have_walls(map) || !map_have_all_elements(map))
        return (0);
    return (1);
}

static int map_is_rectangle(t_map map)
{
	int  i;

	i = 0;
	while (i < map.height)
	{
		if (!map.map || !map.map[i])
			return (0);
		if ((int)ft_strlen(map.map[i]) != map.length)
			return (0);
		i++;
	}
	if (map.height < 3 || map.length < 3)
		return (0);
	return (1);
}

static int map_have_walls(t_map map)
{
	int i;

	i = 0;
	while(i < map.length)
	{
		if (map.map[0][i] != '1')
			return (0);
		if (map.map[map.height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while(i < map.height)
	{
		if (map.map[i][0] != '1')
			return (0);
		if (map.map[i][map.length - 1] != '1')
			return (0);
		i++;
	}	
	return (1);
}


static void search_elemnts(t_map map, int *c, int *e, int *p)
{
	int i;
	int j;

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.length)
		{
			if (map.map[i][j] == COLLECTIBLE)
				(*c)++;
			else if (map.map[i][j] == EXIT)
				(*e)++;
			else if (map.map[i][j] == PLAYER)
				(*p)++;
			j++;
		}
		i++;
	}
}

static int map_have_all_elements(t_map map)
{
	int collect;
	int exit;
	int player;

	collect = 0;
	exit = 0;
	player = 0;
	search_elemnts(map, &collect, &exit, &player);
	if(player > 0 && exit > 0 && collect > 0)
		return (1);
	return (0);
}