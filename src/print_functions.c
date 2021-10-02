#include "push_swap.h"

void	print_stack(char *prefix, t_list2 *stack, char *post_str)
{
	ft_print(prefix, NULL);
	while (stack)
	{
		ft_print_and_free(ft_itoa(*(int *)stack->content),
			ft_strdup(" "), NULL);
		stack = stack->next;
	}
	ft_print(post_str, NULL);
}
