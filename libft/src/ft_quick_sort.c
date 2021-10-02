#include "libft.h"

static int	partition(int *array, int l, int r)
{
	int	x;
	int	less;
	int	i;
	int	tmp;

	x = array[r];
	less = l;
	i = l;
	while (i < r)
	{
		if (array[i] <= x)
		{
			tmp = array[i];
			array[i] = array[less];
			array[less] = tmp;
			less++;
		}
		i++;
	}
	tmp = array[less];
	array[less] = array[r];
	array[r] = tmp;
	return (less);
}

static void	quick_sort_impl(int *array, int l, int r)
{
	int	q;

	if (l < r)
	{
		q = partition(array, l, r);
		quick_sort_impl(array, l, q - 1);
		quick_sort_impl(array, q + 1, r);
	}
}

void	ft_quick_sort(int *array, int len)
{
	quick_sort_impl(array, 0, len - 1);
}
