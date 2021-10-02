#include "push_swap.h"

int	find_pos(int nomber, t_list2 *stack)
{
	int	count;

	count = 1;
	while (stack)
	{
		if (*(int *)stack->content == nomber)
			return (count);
		count++;
		stack = stack->next;
	}
	return (0);
}

static int	find_min(t_list2 *stack, int last_min)
{
	int	min;

	min = __INT_MAX__;
	while (stack)
	{
		if (*(int *)stack->content < min && *(int *)stack->content > last_min)
			min = *(int *)stack->content;
		stack = stack->next;
	}
	return (min);
}

static int	find_max(t_list2 *stack, int last_max)
{
	int	max;

	max = -__INT_MAX__ - 1;
	while (stack)
	{
		if (*(int *)stack->content > max && *(int *)stack->content > last_max)
			max = *(int *)stack->content;
		stack = stack->next;
	}
	return (max);
}

void	go_to_min(char ***path_to_sort, t_list2 **stack_a)
{
	int	len;
	int	min;
	int	pos_min;

	len = ft_lst2_len(*stack_a);
	if (len == 1)
		return ;
	min = find_min(*stack_a, -__INT_MAX__ - 1);
	pos_min = find_pos(min, *stack_a);
	if (pos_min - 1 < len - pos_min + 1)
		while (pos_min-- > 1)
			*path_to_sort = run_instruction_n_add_path("ra", *path_to_sort,
					stack_a, NULL);
	else
		while (pos_min++ <= len)
			*path_to_sort = run_instruction_n_add_path("rra", *path_to_sort,
					stack_a, NULL);
}

void	go_to_max(char ***path_to_sort, t_list2 **stack_b)
{
	int	len;
	int	max;
	int	pos_max;

	len = ft_lst2_len(*stack_b);
	if (len == 0)
		return ;
	max = find_max(*stack_b, -__INT_MAX__ - 1);
	pos_max = find_pos(max, *stack_b);
	if (pos_max == 1)
		return ;
	if (len / 2 - pos_max > 0)
		while (pos_max-- > 1)
			*path_to_sort = run_instruction_n_add_path("rb", *path_to_sort,
					NULL, stack_b);
	else
		while (pos_max++ <= len)
			*path_to_sort = run_instruction_n_add_path("rrb", *path_to_sort,
					NULL, stack_b);
}
