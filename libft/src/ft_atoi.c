#include "libft.h"

static long long	ft_atoi_ll(const char *str)
{
	size_t		i;
	int			flag;
	long long	result;

	result = 0;
	flag = 0;
	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		flag = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (flag)
		result = -result;
	return (result);
}

int	ft_atoi(const char *str)
{
	int	result;

	result = (int)ft_atoi_ll(str);
	return (result);
}

int	ft_check_int(char *str)
{
	int			i;
	int			count;
	long long	num;

	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	count = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		count++;
		i++;
	}
	if (count > 10)
		return (0);
	num = ft_atoi_ll(str);
	if (num > 2147483647 || num < -2147483648)
		return (0);
	return (1);
}
