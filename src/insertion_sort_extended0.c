#include "push_swap.h"

static char	**do_rotate(t_rotate *number_actions,
					t_list2 **stack_a, t_list2 **stack_b, char **sort_path)
{
	if ((*number_actions).ra < 0)
		while ((*number_actions).ra++)
			sort_path = run_instruction_n_add_path("rra", sort_path,
					stack_a, stack_b);
	else if ((*number_actions).ra > 0)
		while ((*number_actions).ra--)
			sort_path = run_instruction_n_add_path("ra", sort_path,
					stack_a, stack_b);
	if ((*number_actions).rb < 0)
		while ((*number_actions).rb++)
			sort_path = run_instruction_n_add_path("rrb", sort_path,
					stack_a, stack_b);
	else if ((*number_actions).rb > 0)
		while ((*number_actions).rb--)
			sort_path = run_instruction_n_add_path("rb", sort_path,
					stack_a, stack_b);
	return (sort_path);
}

static int	get_pos(t_list2 **stack_b, t_rotate *number_actions, int pos, int i)
{
	int	min;
	int	len_b;

	len_b = ft_len_lst2(*stack_b);
	min = ft_abs(number_actions[i].ra) + ft_abs(number_actions[i].rb);
	while (i < len_b)
	{
		if (((number_actions[i].ra > 0 && number_actions[i].rb > 0)
				|| (number_actions[i].ra < 0 && number_actions[i].rb < 0))
			&& max(ft_abs(number_actions[i].ra), ft_abs(number_actions[i].rb))
			< min)
		{
			min = max(ft_abs(number_actions[i].ra),
					  ft_abs(number_actions[i].rb));
			pos = i;
		}
		if (ft_abs(number_actions[i].ra) + ft_abs(number_actions[i].rb) < min)
		{
			min = ft_abs(number_actions[i].ra) + ft_abs(number_actions[i].rb);
			pos = i;
		}
		i++;
	}
	return (pos);
}

static char	**rotate_n_push_items(t_list2 **stack_a, t_list2 **stack_b,
					t_rotate *number_actions, char **sort_path)
{
	int	pos;

	pos = get_pos(stack_b, number_actions, 0, 0);
	sort_path = do_rotate_optimisation_ise(&number_actions[pos],
			stack_a, stack_b, sort_path);
	sort_path = do_rotate(&number_actions[pos], stack_a, stack_b, sort_path);
	sort_path = run_instruction_n_add_path("pa", sort_path,
			stack_a, stack_b);
	return (sort_path);
}

static char	**sort(t_list2 *stack_a, t_list2 *stack_b)
{
	char		**sort_path;
	t_rotate	*number_actions;

	sort_path = first_sort_ise(&stack_a, &stack_b);
	while (stack_b)
	{
		number_actions = get_number_actions(stack_a, stack_b);
		sort_path = rotate_n_push_items(&stack_a, &stack_b, number_actions,
				sort_path);
		free(number_actions);
	}
	go_to_min(&sort_path, &stack_a);
	free_stacks(&stack_a, &stack_b, NULL);
	return (sort_path);
}

char	**insertion_sort_extended(t_push_swap *pswp)
{
	t_list2	*stack_a;
	char	**sort_path;

	stack_a = stack_copy(pswp->stack_a);
	sort_path = sort(stack_a, NULL);
	return (sort_path);
}
