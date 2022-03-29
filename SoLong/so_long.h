#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
#include "get_next_line/get_next_line.h"

# define COLLECTIBLE	'C'
# define EXIT			'E'
# define PLAYER			'P'


typedef struct s_map
{
	int length;
	int height;
	char **map;
} t_map;

/* get_map.c */
t_map get_map(char *map_path);

/* map_validations.c*/
int map_validation(t_map map);

#endif