#include "so_long.h"

//gcc so_long.c get_map.c get_next_line/get_next_line_utils.c get_next_line/get_next_line.c

int main(int argc, char **argv)
{
    char **map;
    int i;

    if (argc != 2)
    {
        printf("Wrong parmeters: You have to indicate the path of map\n");
        return (0);
    }
    map = get_map(argv[1]);

    i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
    return (0);
}