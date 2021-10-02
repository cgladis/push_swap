#include "libft.h"

long double	ft_abs_ld(long double number)
{
	if (number < 0)
		number = -number;
	return (number);
}

int	ft_abs(int number)
{
	if (number < 0)
		number = -number;
	return (number);
}
