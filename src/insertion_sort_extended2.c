#include "push_swap.h"

char	**do_rotate_optimisation_ise(t_rotate *number_actions,
			t_list2 **stack_a, t_list2 **stack_b, char **sort_path)
{
	if ((*number_actions).ra < 0 && (*number_actions).rb < 0)
	{
		while ((*number_actions).ra && (*number_actions).rb)
		{
			sort_path = run_instruction_n_add_path("rrr",
					sort_path, stack_a, stack_b);
			(*number_actions).ra++;
			(*number_actions).rb++;
		}
	}
	if ((*number_actions).ra > 0 && (*number_actions).rb > 0)
	{
		while ((*number_actions).ra && (*number_actions).rb)
		{
			sort_path = run_instruction_n_add_path("rr",
					sort_path, stack_a, stack_b);
			(*number_actions).ra--;
			(*number_actions).rb--;
		}
	}
	return (sort_path);
}
