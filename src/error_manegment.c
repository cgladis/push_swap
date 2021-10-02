#include "push_swap.h"

void	*free_stacks(t_list2 **stack_a, t_list2 **stack_b, int *num)
{
	if (stack_a)
	{
		if (*stack_a)
		{
			ft_lst2clear(*stack_a, free);
			*stack_a = NULL;
		}
	}
	if (stack_b)
	{
		if (*stack_b)
		{
			ft_lst2clear(*stack_b, free);
			*stack_b = NULL;
		}
	}
	if (num)
		free(num);
	return (NULL);
}

int	free_pswp(t_push_swap *pswp)
{
	if (pswp->stack_a)
		ft_lst2clear(pswp->stack_a, free);
	if (pswp->shotest_path)
		ft_free_str_lines(pswp->shotest_path);
	if (pswp->algorithm)
		free(pswp->algorithm);
	return (0);
}

int	check_stack_a(t_list2 *stack_a, int *item)
{
	stack_a = ft_lst2first(stack_a);
	while (stack_a)
	{
		if (*(int *)stack_a->content == *item)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	*print_error(t_list2 **stack_a, t_list2 **stack_b, int *num)
{
	free_stacks(stack_a, stack_b, num);
	ft_print("Error\n", NULL);
	return (NULL);
}
