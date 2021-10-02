#include "push_swap.h"

static void	print_lines(t_list2 *stack_a, t_list2 *stack_b, t_push_swap *pswp)
{
	char	**ptr;
	int		i;

	i = 1;
	ptr = pswp->shotest_path;
	while (*ptr)
	{
		if (PRINT_CHECK == 1)
			ft_print_and_free(ft_itoa(i), ft_strdup(".  \t"), NULL);
		ft_print(*ptr, NULL);
		if (PRINT_CHECK == 1)
		{
			run_instruction(*ptr, &stack_a, &stack_b);
			print_stack("  \t| stack a: ", stack_a, " | ");
			print_stack(" stack b: ", stack_b, "");
		}
		ft_print("\n", NULL);
		ptr++;
		i++;
	}
}

static void	print_shortest_path(t_push_swap *pswp)
{
	t_list2	*stack_a;
	t_list2	*stack_b;

	if (pswp->shotest_path == NULL)
		return ;
	stack_a = stack_copy(pswp->stack_a);
	stack_b = NULL;
	if (PRINT_ALL)
		ft_print("\e[34mAlgorithm: \e[33m", pswp->algorithm, "\e[0m\n", NULL);
	if (PRINT_CHECK == 1)
		print_stack("\e[34mSource stacks:	| stack a: \e[36m", stack_a,
			" |  stack b:\e[0m\n");
	print_lines(stack_a, stack_b, pswp);
	free_stacks(&stack_a, &stack_b, NULL);
}

void	compare_algorithms(t_push_swap *pswp, char *algorithm,
						   char **sorting_path)
{
	if (PRINT_ALL == 1)
	{
		print_shortest_path(pswp);
		ft_free_str_lines(pswp->shotest_path);
		pswp->shotest_path = sorting_path;
		free(pswp->algorithm);
		pswp->algorithm = ft_strdup(algorithm);
	}
	else
	{
		if (pswp->shotest_path == NULL || ft_len((void **)pswp->shotest_path)
			> ft_len((void **)sorting_path))
		{
			ft_free_str_lines(pswp->shotest_path);
			pswp->shotest_path = sorting_path;
			free(pswp->algorithm);
			pswp->algorithm = ft_strdup(algorithm);
		}
		else
			ft_free_str_lines(sorting_path);
	}
}

int	main(int argc, char **argv)
{
	t_push_swap	pswp;

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
	if (is_stack_sorted(pswp.stack_a))
	{
		compare_algorithms(&pswp, "First Check", first_check(&pswp));
		print_shortest_path(&pswp);
		return (free_pswp(&pswp));
	}
	compare_algorithms(&pswp, "Bubble Sort", buble_sort(&pswp));
	compare_algorithms(&pswp, "Insertion Sort", insertion_sort(&pswp));
	compare_algorithms(&pswp, "Insertion Sort Extended",
		insertion_sort_extended(&pswp));
	print_shortest_path(&pswp);
	free_pswp(&pswp);
}
