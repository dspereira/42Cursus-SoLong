#include "so_long.h"

static int get_num_lines(char *path);
static t_map *get_map_from_file(t_map *map, char *path);
static char **init_map(int size);

t_map *get_map(t_data *data, char *map_path)
{
	t_map	*map;

	map = &(data->map);
	map_error(is_file_type_ber(map_path), "Map is not \".ber\" extension\n");
	get_map_from_file(map, map_path);
	map_error(map_validation(*map), "Misconfiguration Map\n");
	return (map);
}

static int get_num_lines(char *path)
{
	int		fd;
	int		n_lines;
	char	buff;

	fd = sys_error(open(path, O_RDONLY));
	n_lines = 0;
	buff = '\n';
	while (sys_error(read(fd, &buff, 1)))
	{
		if (buff == '\n')
			n_lines++;
	}
	if (buff != '\n')
		n_lines++;
	sys_error(close(fd));
	if (!n_lines)
		return (-1);
	return (n_lines);
}

static t_map *get_map_from_file(t_map *map, char *path)
{
	int fd;
	int len;
	int i;

	map->height = map_error(get_num_lines(path), "File is empty\n");
	if(map->height)
		map->map = init_map(map->height);
	fd = sys_error(open(path, O_RDONLY));
	i = 0;
	while (i < map->height)
	{
		map->map[i] = oom_guard(get_next_line(fd));
		if (map->map[i])
		{
			len = ft_strlen(map->map[i]);
			if (map->map[i][len - 1] == '\n')
				map->map[i][len - 1] = '\0';
		}
		i++;
	}
	map->length = ft_strlen(map->map[0]);
	sys_error(close(fd));
	return (map);
}

static char **init_map(int size)
{	
	char **map;
	int i;

	map = oom_guard(malloc(size * sizeof(char *)));
	i = 0;
	while (i < size)
	{
		map[i] = 0;
		i++;
	}
	return (map);
}


int is_file_type_ber(char *file)
{
	int size;
	char *ext;
	int ext_size;
	int  i;

	if (!file)
		return (-1);
	size = ft_strlen(file);
	ext_size = ft_strlen(EXT);
	if (size <= ext_size)
		return (-1);
	ext = file + (size - ext_size);
	i = 0;
	while (EXT[i] != '\0')
	{
		if (ext[i] != EXT[i])
			return (-1);
		i++;
	}
	return (1);
} 

void free_map(t_map map)
{
	int i;
	char **m;

	m = map.map;
	if (!m)
		return ;
	i = 0;
	while (i < map.height)
	{
		if (m[i])
			free(m[i]);
		i++;
	}
	free(m);
}