#include "push_swap.h"

static char	**sort_3_items(t_list2 **stack_a, t_list2 **stack_b,
						   char **sort_path, int *min_med_max)
{
	if (*(int *)(*stack_a)->content
		> *(int *)(*stack_a)->next->content
		&& !(*(int *)(*stack_a)->content == min_med_max[2]
		&& *(int *)(*stack_a)->next->content == min_med_max[0]))
		sort_path = run_instruction_n_add_path("sa", sort_path,
				stack_a, stack_b);
	else if (*(int *)(*stack_a)->next->content
		> *(int *)(*stack_a)->next->next->content
		&& !(*(int *)(*stack_a)->next->content == min_med_max[2]
		&& *(int *)(*stack_a)->next->next->content == min_med_max[0]))
	{
		sort_path = run_instruction_n_add_path("ra", sort_path,
				stack_a, stack_b);
		sort_path = run_instruction_n_add_path("sa", sort_path,
				stack_a, stack_b);
	}
	return (sort_path);
}

char	**push_in_stack_b(t_list2 **stack_a, t_list2 **stack_b,
					   int *min_med_max, char **sort_path)
{
	if ((*(int *)(*stack_a)->content != min_med_max[0])
	&& (*(int *)(*stack_a)->content != min_med_max[1])
	&& (*(int *)(*stack_a)->content != min_med_max[2]))
	{
		sort_path = run_instruction_n_add_path("pb", sort_path,
				stack_a, stack_b);
		if (*(int *)(*stack_b)->content >= min_med_max[1])
			sort_path = run_instruction_n_add_path("rb", sort_path,
					stack_a, stack_b);
	}
	else
		sort_path = run_instruction_n_add_path("ra", sort_path,
				stack_a, stack_b);
	return (sort_path);
}

char	**first_sort_ise(t_list2 **stack_a, t_list2 **stack_b)
{
	int		min_med_max[3];
	int		len;
	char	**sort_path;

	sort_path = NULL;
	min_med_max[1] = find_medium_item(*stack_a);
	min_n_max_item(*stack_a, &min_med_max[0], &min_med_max[2]);
	len = ft_lst2_len(*stack_a);
	if (len > 3)
		while (len--)
			sort_path = push_in_stack_b(stack_a, stack_b, min_med_max,
					sort_path);
	sort_path = sort_3_items(stack_a, stack_b, sort_path, min_med_max);
	return (sort_path);
}

int	find_pos_in_stack_a(t_list2 *stack_a, int num)
{
	int	j;

	j = 1;
	if (num > *(int *)ft_lst2last(stack_a)->content
		&& num < *(int *)stack_a->content)
		return (0);
	while (stack_a->next)
	{
		if (num > *(int *)stack_a->content
			&& num < *(int *)stack_a->next->content)
			return (j);
		j++;
		stack_a = stack_a->next;
	}
	return (0);
}

t_rotate	*get_number_actions(t_list2 *stack_a, t_list2 *stack_b)
{
	t_rotate	*rotate;
	int			len_b;
	int			len_a;
	int			i;

	len_b = ft_len_lst2(stack_b);
	len_a = ft_lst2_len(stack_a);
	rotate = (t_rotate *)malloc(sizeof(t_rotate) * len_b);
	i = 0;
	while (stack_b)
	{
		rotate[i].rb = i;
		rotate[i].ra = find_pos_in_stack_a(stack_a, *(int *)stack_b->content);
		rotate[i] = minimum_rotate(rotate[i].ra, len_a - rotate[i].ra,
				rotate[i].rb, len_b - rotate[i].rb);
		i++;
		stack_b = stack_b->next;
	}
	return (rotate);
}
