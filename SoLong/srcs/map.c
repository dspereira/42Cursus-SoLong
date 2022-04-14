#include "so_long.h"

//IMPORTANTE: segfoult quando o ficheiro está vazio.

static int get_num_lines(char *path);
static t_map get_map_from_file(char *path);

t_map get_map(char *map_path)
{
	t_map map;

	map = get_map_from_file(map_path);
	if(map_validation(map))
		printf("MAPA CERTO\n");
	else 
		printf("MAPA ERADO\n");

	return (map);
}

static int get_num_lines(char *path)
{
	int		fd;
	int		n_lines;
	char	buff;

	fd = open(path, O_RDONLY);
	n_lines = 0;
	while (read(fd, &buff, 1))
	{
		if (buff == '\n')
			n_lines++;
	}
	n_lines++;
	close(fd);
	return (n_lines);
}

static t_map get_map_from_file(char *path)
{
	t_map map;
	int fd;
	int len;
	int i;

	map.height = get_num_lines(path);
	if(map.height)
		map.map = oom_guard(malloc((map.height) * sizeof(char *)));
	fd = open(path, O_RDONLY);
	i = 0;
	while (i < map.height)
	{
		map.map[i] = get_next_line(fd);
		if (map.map[i])
		{
			len = ft_strlen(map.map[i]);
			if (map.map[i][len - 1] == '\n')
				map.map[i][len - 1] = '\0';
		}
		i++;
	}
	map.length = ft_strlen(map.map[0]);
	close(fd);
	return (map);
}

void free_map(t_map map)
{
	int i;

	i = 0;
	while (i < map.height)
	{
		if (map.map[i])
			free(map.map[i]);
		i++;
	}
	if (map.map)
		free(map.map);
}