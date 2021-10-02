#include "push_swap.h"

char	**insertion_sort(t_push_swap *pswp)
{
	t_list2	*stack_a;
	char	**sort_path;

	stack_a = stack_copy(pswp->stack_a);
	sort_path = _insertion_sort(stack_a, NULL);
	return (sort_path);
}
