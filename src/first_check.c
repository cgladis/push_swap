#include "push_swap.h"

char	**first_check(t_push_swap *pswp)
{
	t_list2	*stack_a;
	char	**sort_path;

	sort_path = NULL;
	stack_a = stack_copy(pswp->stack_a);
	go_to_min(&sort_path, &stack_a);
	free_stacks(&stack_a, NULL, NULL);
	return (sort_path);
}
