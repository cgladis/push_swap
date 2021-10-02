#include "push_swap.h"

static int	get_pos(t_list2 *stack_b, int num, int min, int max)
{
	int		current;
	int		count;

	current = *(int *)ft_lst2last(stack_b)->content;
	count = 0;
	while (stack_b)
	{
		if ((current > num && num > *(int *)stack_b->content)
			|| (num > max && *(int *)stack_b->content == max)
			|| (num < min && current == min))
			break ;
		current = *(int *)stack_b->content;
		count++;
		stack_b = stack_b->next;
	}
	return (count);
}

static char	**get_pos_n_rotate_stack(t_list2 **stack_a, t_list2 **stack_b,
									 int num, char **path_to_sort)
{
	int		len;
	int		count;
	int		max;
	int		min;

	min_n_max_item(*stack_b, &min, &max);
	count = get_pos(*stack_b, num, min, max);
	len = ft_lst2_len(*stack_b);
	if (count < len / 2 && len > 1)
	{
		while (count--)
			path_to_sort = run_instruction_n_add_path("rb", path_to_sort,
					stack_a, stack_b);
	}
	else if (count >= len / 2 && len > 1)
	{
		while (count++ < len)
			path_to_sort = run_instruction_n_add_path("rrb", path_to_sort,
					stack_a, stack_b);
	}
	return (path_to_sort);
}

static void	past_item_to_stack_b(t_list2 **stack_a, t_list2 **stack_b, int num,
									char ***path_to_sort)
{
	int		len;

	if (!*stack_b)
	{
		*path_to_sort = run_instruction_n_add_path("pb", *path_to_sort,
				stack_a, stack_b);
		return ;
	}
	len = ft_lst2_len(*stack_b);
	*path_to_sort = get_pos_n_rotate_stack(stack_a, stack_b, num,
			*path_to_sort);
	*path_to_sort = run_instruction_n_add_path("pb", *path_to_sort,
			stack_a, stack_b);
	if (len == 1 && *(int *)(*stack_b)->content
	        < *(int *)(*stack_b)->next->content)
		*path_to_sort = run_instruction_n_add_path("rb", *path_to_sort, stack_a,
				stack_b);
}

static char	**first_sort(t_list2 **stack_a, t_list2 **stack_b)
{
	char	**path_to_sort;
	int		max;
	int		min;
	int		num;

	path_to_sort = NULL;
	min_n_max_item(*stack_a, &min, &max);
	num = *(int *)ft_lst2last(*stack_a)->content;
	while (!is_stack_sorted(*stack_a))
	{
		if (num > *(int *)(*stack_a)->content && !(num == max && *(int *)
			(*stack_a)->content == min))
		{
			past_item_to_stack_b(stack_a, stack_b, *(int *)(*stack_a)->content,
				&path_to_sort);
		}
		else
			path_to_sort = run_instruction_n_add_path("ra", path_to_sort,
					stack_a, stack_b);
		num = *(int *)ft_lst2last(*stack_a)->content;
	}
	go_to_min(&path_to_sort, stack_a);
	go_to_max(&path_to_sort, stack_b);
	return (path_to_sort);
}

char	**_insertion_sort(t_list2 *stack_a, t_list2 *stack_b)
{
	char	**path_to_sort;
	int		max;
	int		min;

	path_to_sort = first_sort(&stack_a, &stack_b);
	min_n_max_item(stack_a, &min, &max);
	path_to_sort = run_instruction_n_add_path("rra", path_to_sort, &stack_a,
			&stack_b);
	while (ft_lst2_len(stack_b) != 0)
		if (*(int *)stack_b->content >= *(int *)ft_lst2last(stack_a)->content)
			path_to_sort = run_instruction_n_add_path("pa", path_to_sort,
					&stack_a, &stack_b);
	else
	{
		path_to_sort = run_instruction_n_add_path("rra", path_to_sort,
				&stack_a, &stack_b);
		if (*(int *)stack_a->content == min)
			while (ft_lst2_len(stack_b) != 0)
				path_to_sort = run_instruction_n_add_path("pa",
						path_to_sort, &stack_a, &stack_b);
	}
	go_to_min(&path_to_sort, &stack_a);
	free_stacks(&stack_a, &stack_b, NULL);
	return (path_to_sort);
}
