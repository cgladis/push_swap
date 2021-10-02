#include "push_swap.h"

void	swap(t_list2 **stack)
{
	t_list2	*old_first;
	t_list2	*old_second;
	t_list2	*third;

	if (ft_lst2_len(*stack) < 2)
		return ;
	old_first = ft_lst2first(*stack);
	old_second = old_first->next;
	third = old_second->next;
	old_second->previous = NULL;
	old_second->next = old_first;
	old_first->previous = old_second;
	old_first->next = third;
	if (third)
		third->previous = old_first;
	*stack = old_second;
}

void	push(t_list2 **stack_src, t_list2 **stack_dst)
{
	t_list2	*first_src;
	t_list2	*second_src;
	t_list2	*first_dst;

	if (!stack_src || !*stack_src)
		return ;
	first_src = ft_lst2first(*stack_src);
	second_src = first_src->next;
	if (second_src)
		second_src->previous = NULL;
	*stack_src = second_src;
	if (*stack_dst)
	{
		first_dst = ft_lst2first(*stack_dst);
		first_dst->previous = first_src;
	}
	else
		first_dst = NULL;
	first_src->next = first_dst;
	*stack_dst = first_src;
}

void	rotate(t_list2 **stack)
{
	t_list2	*ptr_old_first;
	t_list2	*ptr_old_last;
	t_list2	*ptr_new_first;

	if (!stack || ft_len_lst2(*stack) < 2)
		return ;
	ptr_old_first = ft_lst2first(*stack);
	ptr_old_last = ft_lst2last(*stack);
	ptr_new_first = ptr_old_first->next;
	ptr_new_first->previous = NULL;
	ptr_old_last->next = ptr_old_first;
	ptr_old_first->previous = ptr_old_last;
	ptr_old_first->next = NULL;
	*stack = ptr_new_first;
}

void	reverse_rotate(t_list2 **stack)
{
	t_list2	*ptr_old_first;
	t_list2	*ptr_old_last;
	t_list2	*ptr_new_last;

	if (!stack || ft_len_lst2(*stack) < 2)
		return ;
	ptr_old_last = ft_lst2last(*stack);
	ptr_old_first = ft_lst2first(*stack);
	ptr_new_last = ptr_old_last->previous;
	ptr_new_last->next = NULL;
	ptr_old_first->previous = ptr_old_last;
	ptr_old_last->previous = NULL;
	ptr_old_last->next = ptr_old_first;
	*stack = ptr_old_last;
}
