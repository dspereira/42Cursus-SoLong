#include "so_long.h"
#include "get_next_line/get_next_line.h"

static int get_num_lines(char *path);
static char **get_map_from_file(char *path);
int validate_map(char **map);

char **get_map(char *map_path)
{
	char **map;

	map = get_map_from_file(map_path);
	if (validate_map(map))
		printf("Mapa válido\n");
	else
		printf("Mapa ERRADO\n");


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

static char **get_map_from_file(char *path)
{
	char **map;
	int	num_lines;
	int fd;
	int len;
	int i;

	num_lines = get_num_lines(path);
	if(num_lines)
		map = malloc((num_lines + 1) * sizeof(char *));
	fd = open(path, O_RDONLY);
	i = 0;

	while (i < num_lines)
	{
		// Se o retorno do get_next_line for 0 então já o mapa é errado validar isso
		map[i] = get_next_line(fd);
		len = ft_strlen(map[i]);
		if (map[i][len - 1] == '\n')
			map[i][len - 1] = '\0';
		i++;
	}
	map[i] = 0;
	close(fd);
	return (map);
}

int validate_map(char **map)
{
	int lengh;
	int i;

	lengh = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != lengh)
			return (0);
		i++;
	}
	return (1);
}

