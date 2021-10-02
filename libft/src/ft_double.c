#include "libft.h"

static double	get_result_part1(char **nbr)
{
	double	result_part1;

	result_part1 = 0;
	while (ft_isdigit(**nbr))
	{
		result_part1 = result_part1 * 10 + (**nbr - '0');
		(*nbr)++;
	}
	return (result_part1);
}

static double	get_result_part2(char **nbr)
{
	double	result_part2;

	result_part2 = 0;
	while (ft_isdigit(**nbr))
		(*nbr)++;
	(*nbr)--;
	while (ft_isdigit(**nbr))
	{
		result_part2 = (result_part2 + (**nbr - '0')) / 10;
		(*nbr)--;
	}
	return (result_part2);
}

double	ft_double(char *nbr)
{
	double	result_part1;
	double	result_part2;
	int		minus;
	double	result;

	if (nbr == NULL)
		return (0);
	minus = 0;
	if (*nbr == '-')
	{
		minus = 1;
		nbr++;
	}
	result_part1 = get_result_part1(&nbr);
	result_part2 = 0;
	if (*nbr == '.')
	{
		nbr++;
		result_part2 = get_result_part2(&nbr);
	}
	result = result_part1 + result_part2;
	if (minus)
		result = -result;
	return (result);
}
