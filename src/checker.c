#include "push_swap.h"

static void	free_n_NULL(char **str)
{
	if (str)
	{
		if (*str)
		{
			free(*str);
			*str = NULL;
		}
	}
}

static int	run_commands(t_list2 *stack_a, t_list2 *stack_b, t_push_swap pswp)
{
	char	*command;
	int		min;
	int		max;
	int		len;

	command = NULL;
	while (get_next_line(0, &command))
	{
		if (run_instruction(command, &stack_a, &stack_b) == -1)
		{
			print_error(&stack_a, &stack_b, NULL);
			return (-1);
		}
		free_n_NULL(&command);
	}
	free_n_NULL(&command);
	len = ft_lst2_len(stack_a);
	min_n_max_item(stack_a, &min, &max);
	if (*(int *)stack_a->content == min && pswp.number_items == len
		&& is_stack_sorted(stack_a))
		ft_print("OK\n", NULL);
	else
		ft_print("KO\n", NULL);
	free_stacks(&stack_a, &stack_b, NULL);
	return (1);
}

int	main(int argc, char **argv)
{
	t_push_swap	pswp;
	t_list2		*stack_a;

	if (PRINT_CHECK || PRINT_ALL)
		return (0);
	if (argc < 2)
	{
		ft_print("Error\n", NULL);
		return (0);
	}
	if (!init_pswp(&pswp, argv))
	{
		free_pswp(&pswp);
		print_error(NULL, NULL, NULL);
		return (0);
	}
	stack_a = stack_copy(pswp.stack_a);
	if (!stack_a)
	{
		free_pswp(&pswp);
		print_error(NULL, NULL, NULL);
		return (0);
	}
	run_commands(stack_a, NULL, pswp);
	free_pswp(&pswp);
}
