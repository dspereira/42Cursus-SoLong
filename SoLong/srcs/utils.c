#include "so_long.h"

static int	get_size(long int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}	
	return (i);
}

char	*ft_itoa(int n)
{
	int			size;
	char		*str;
	long int	nbr;

	nbr = (long int) n;
	size = get_size(nbr);
	str = oom_guard(malloc((1 + size) * sizeof(char)));
	if (!str)
		return (0);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	else if (nbr == 0)
		str[0] = '0';
	str[size] = '\0';
	while (nbr > 0)
	{
		str[--size] = (nbr - ((nbr / 10) * 10)) + '0';
		nbr /= 10;
	}
	return (str);
}
