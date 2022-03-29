#include "so_long.h"

//gcc so_long.c get_map.c get_next_line/get_next_line_utils.c get_next_line/get_next_line.c

// função de teste durante o desenvolvimento
void print_map(t_map map)
{
    int i; 
    
    i = 0;
    printf("mapa h: %i\n", map.height);
    printf("mapa l: %i\n", map.length);
    while(i < map.height)
    {
        if (map.map[i])
            printf("%s\n", map.map[i]);
        else 
            printf("\n");
        i++;
    }
}

int main(int argc, char **argv)
{
    t_map map;

    if (argc != 2)
    {
        printf("Wrong parmeters: You have to indicate the path of map\n");
        return (0);
    }
    map = get_map(argv[1]);
    print_map(map);
    return (0);
}