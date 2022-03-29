#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct s_map
{
	int length;
	int height;
	char **map;
} t_map;

t_map get_map(char *map_path);

#endif