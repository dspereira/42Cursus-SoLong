#include "so_long.h"
#include "get_next_line/get_next_line.h"

static int get_num_lines(char *path);

char **get_map(char *map_path)
{
	char **map;
	int num_lines;
	int fd;
	int i;

	num_lines = get_num_lines(map_path);
	if(num_lines)
		map = malloc((num_lines + 1) * sizeof(char *));
	
	fd = open(map_path, O_RDONLY);
	i = 0;
	while (i < num_lines)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = 0;
	close(fd);
	return (map);
}

static int get_num_lines(char *path)
{
	int fd;
	int n_lines;
	char buff[1];

	fd = open(path, O_RDONLY);
	n_lines = 0;
	read(fd, buff, 1);
	while (read(fd, buff, 1))
	{
		if (buff[0] == '\n')
			n_lines++;
	}
	n_lines++;
	close(fd);
	return (n_lines);
}