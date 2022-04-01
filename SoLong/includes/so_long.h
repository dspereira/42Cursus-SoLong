#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
#include "../get_next_line/get_next_line.h"

# define COLLECTIBLE	'C'
# define EXIT			'E'
# define PLAYER			'P'
# define GRASS			'0'
# define TREE			'1'

# define GRASS_PATH 	"./assets/grass.xpm"
# define TREE_PATH 		"./assets/tree.xpm"
# define PLAYER_PATH 	"./assets/player.xpm"

# define IMG_SIZE		60

typedef struct s_map
{
	int length;
	int height;
	char **map;
} t_map;

typedef struct s_imgs
{
	void *grass;
	void *tree;
	void *player;
}	t_imgs; 


/* get_map.c */
t_map get_map(char *map_path);

/* map_validations.c*/
int map_validation(t_map map);

#endif