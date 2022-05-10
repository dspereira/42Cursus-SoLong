#include "so_long.h"

//IMPORTANTE: segfoult quando o ficheiro está vazio.

static int get_num_lines(char *path);
static t_map get_map_from_file(char *path);

t_map get_map(char *map_path)
{
	t_map	map;

	map_error(is_file_type_ber(map_path), "Map is not \".ber\" extension\n");
	map = get_map_from_file(map_path);
	map_error(map_validation(map), "Misconfiguration Map\n");
	return (map);
}

static int get_num_lines(char *path)
{
	int		fd;
	int		n_lines;
	char	buff;

	fd = sys_error(open(path, O_RDONLY));
	n_lines = 0;
	while (sys_error(read(fd, &buff, 1)))
	{
		if (buff == '\n')
			n_lines++;
	}
	n_lines++;
	sys_error(close(fd));
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
	fd = sys_error(open(path, O_RDONLY));
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
	sys_error(close(fd));
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