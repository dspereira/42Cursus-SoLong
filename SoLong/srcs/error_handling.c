#include "so_long.h"

void	*oom_guard(void *p)
{
	if (!p)
	{
		printf("%s: Out of memory!\n", "Solong");
		exit(EXIT_FAILURE);
	}
	return (p);
}