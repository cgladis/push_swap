#include "push_swap.h"

static char	**do_rotate(t_list2 **stack_a, t_push_swap *pswp,
				char **path_to_sort)
{
	if (pswp->round % 2 == 1)
	{
		run_instruction("ra", stack_a, NULL);
		path_to_sort = ft_add_str_and_free_str1(path_to_sort, "ra");
		pswp->cur_item++;
		if (pswp->cur_item == pswp->sort_pos2)
		{
			pswp->sort_pos2--;
			pswp->round++;
		}
	}
	else
	{
		run_instruction("rra", stack_a, NULL);
		path_to_sort = ft_add_str_and_free_str1(path_to_sort, "rra");
		pswp->cur_item--;
		if (pswp->cur_item == pswp->sort_pos1)
		{
			pswp->sort_pos1++;
			pswp->round++;
		}
	}
	return (path_to_sort);
}

static char	**sort(t_list2 *stack_a, t_push_swap *pswp)
{
	char	**path_to_sort;

	path_to_sort = NULL;
	pswp->round = 1;
	pswp->sort_pos1 = 1;
	pswp->sort_pos2 = pswp->number_items - 1;
	pswp->cur_item = 1;
	while (!is_stack_sorted(stack_a))
	{
		if (*(int *)stack_a->content > *(int *)stack_a->next->content)
		{
			run_instruction("sa", &stack_a, NULL);
			path_to_sort = ft_add_str_and_free_str1(path_to_sort, "sa");
		}
		path_to_sort = do_rotate(&stack_a, pswp, path_to_sort);
	}
	go_to_min(&path_to_sort, &stack_a);
	return (path_to_sort);
}

char	**buble_sort(t_push_swap *pswp)
{
	t_list2	*stack_a_copy;
	char	**sort_path;

	stack_a_copy = stack_copy(pswp->stack_a);
	sort_path = sort(stack_a_copy, pswp);
	free_stacks(&stack_a_copy, NULL, NULL);
	return (sort_path);
}
