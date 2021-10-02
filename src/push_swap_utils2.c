#include "push_swap.h"

int	find_medium_item(t_list2 *stack_a)
{
	int	*array;
	int	i;
	int	len;
	int	medium;

	i = 0;
	len = ft_lst2_len(stack_a);
	array = (int *)malloc(sizeof(int) * len);
	while (stack_a)
	{
		array[i] = *(int *)stack_a->content;
		i++;
		stack_a = stack_a->next;
	}
	if (len > 0)
		ft_quick_sort(array, len);
	medium = array[(len - 1) / 2];
	free(array);
	return (medium);
}

t_rotate	minimum_rotate(int ra, int rra, int rb, int rrb)
{
	t_rotate	rotate;
	int			min[4];
	int			minimum;
	int			i;

	rotate = (t_rotate){0, 0};
	min[0] = max(ra, rb);
	min[1] = max(rra, rrb);
	min[2] = ra + rrb;
	min[3] = rra + rb;
	minimum = min[0];
	i = 0;
	while (i++ < 3)
		if (min[i] < minimum)
			minimum = min[i];
	if (minimum == max(ra, rb))
		rotate = (t_rotate){ra, rb};
	else if (minimum == max(rra, rrb))
		rotate = (t_rotate){-rra, -rrb};
	else if (minimum == ra + rrb)
		rotate = (t_rotate){ra, -rrb};
	else if (minimum == rra + rb)
		rotate = (t_rotate){-rra, rb};
	return (rotate);
}

static int	check_number(char *number)
{
	if (*number == '-' || *number == '+')
		number++;
	while (*number)
	{
		if (!ft_isdigit(*number))
			return (0);
		number++;
	}
	return (1);
}

static t_list2	*malloc_stacks(char **argv)
{
	t_list2	*stack_a;
	t_list2	*newlist;
	int		*num;

	stack_a = NULL;
	while (*argv)
	{
		num = (int *) malloc(sizeof(int));
		if (!num || !check_number(*argv) || !ft_check_int(*argv))
			return (free_stacks(&stack_a, NULL, num));
		*num = ft_atoi(*argv);
		if (!check_stack_a(stack_a, num))
			return (free_stacks(&stack_a, NULL, num));
		newlist = ft_lst2new(num);
		if (!newlist)
			return (free_stacks(&stack_a, NULL, num));
		ft_lst2add_back(&stack_a, newlist);
		argv++;
	}
	return (stack_a);
}

int	init_pswp(t_push_swap *pswp, char **argv)
{
	pswp->shotest_path = NULL;
	pswp->algorithm = NULL;
	pswp->stack_a = malloc_stacks(argv + 1);
	if (pswp->stack_a == NULL)
		return (0);
	pswp->number_items = ft_len_lst2(pswp->stack_a);
	return (1);
}
