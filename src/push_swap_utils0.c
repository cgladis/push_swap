#include "push_swap.h"

t_list2	*stack_copy(t_list2 *stack)
{
	t_list2	*new_stack;
	int		*num;

	new_stack = NULL;
	while (stack)
	{
		num = (int *) malloc(sizeof(int));
		*num = *(int *)stack->content;
		ft_lst2add_back(&new_stack, ft_lst2new(num));
		stack = stack->next;
	}
	return (new_stack);
}

int	is_stack_sorted(t_list2 *stack)
{
	int	num;
	int	i;
	int	min;
	int	max;

	i = 0;
	if (!stack)
		return (0);
	stack = ft_lst2first(stack);
	min_n_max_item(stack, &min, &max);
	num = *(int *)ft_lst2last(stack)->content;
	while (stack)
	{
		if (num > *(int *)stack->content && !(num == max
				&& *(int *)stack->content == min))
			return (0);
		num = *(int *)stack->content;
		stack = stack->next;
		i++;
	}
	return (i);
}

//char	**get_command_list(void)
//{
//	char	**command_list;
//
//	command_list = NULL;
//	command_list = ft_add_str_and_free_str1(command_list, "sa");
//	command_list = ft_add_str_and_free_str1(command_list, "sb");
//	command_list = ft_add_str_and_free_str1(command_list, "ss");
//	command_list = ft_add_str_and_free_str1(command_list, "pa");
//	command_list = ft_add_str_and_free_str1(command_list, "pb");
//	command_list = ft_add_str_and_free_str1(command_list, "ra");
//	command_list = ft_add_str_and_free_str1(command_list, "rb");
//	command_list = ft_add_str_and_free_str1(command_list, "rr");
//	command_list = ft_add_str_and_free_str1(command_list, "rra");
//	command_list = ft_add_str_and_free_str1(command_list, "rrb");
//	command_list = ft_add_str_and_free_str1(command_list, "rrr");
//	return (command_list);
//}

void	min_n_max_item(t_list2 *stack, int *min, int *max)
{
	stack = ft_lst2first(stack);
	*min = *(int *)stack->content;
	*max = *(int *)stack->content;
	while (stack)
	{
		if (*(int *)stack->content > *max)
			*max = *(int *)stack->content;
		if (*(int *)stack->content < *min)
			*min = *(int *)stack->content;
		stack = stack->next;
	}
}

int	max(int num1, int num2)
{
	if (num1 > num2)
		return (num1);
	else
		return (num2);
}
