#include "push_swap.h"

static int	check_instruction(char *instruction, t_list2 **stack_a,
								t_list2 **stack_b)
{
	int	len_a;
	int	len_b;

	len_a = 0;
	len_b = 0;
	if (stack_a != NULL)
		len_a = ft_lst2_len(*stack_a);
	if (stack_b != NULL)
		len_b = ft_lst2_len(*stack_b);
	if ((!ft_strcmp(instruction, "sa") || !ft_strcmp(instruction, "ra")
			|| !ft_strcmp(instruction, "rra")) && len_a <= 1)
		return (0);
	if ((!ft_strcmp(instruction, "sb") || !ft_strcmp(instruction, "rb")
			|| !ft_strcmp(instruction, "rrb")) && len_b <= 1)
		return (0);
	if ((!ft_strcmp(instruction, "ss") || !ft_strcmp(instruction, "rr")
			|| !ft_strcmp(instruction, "rrr")) && len_b <= 1 && len_a <= 1)
		return (0);
	if (!ft_strcmp(instruction, "pa") && len_b == 0)
		return (0);
	if (!ft_strcmp(instruction, "pb") && len_a == 0)
		return (0);
	return (1);
}

static void	run_rotate(char *instruction, t_list2 **stack_a, t_list2 **stack_b)
{
	if (!ft_strcmp(instruction, "ra"))
		rotate(stack_a);
	if (!ft_strcmp(instruction, "rb"))
		rotate(stack_b);
	if (!ft_strcmp(instruction, "rr"))
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	if (!ft_strcmp(instruction, "rra"))
		reverse_rotate(stack_a);
	if (!ft_strcmp(instruction, "rrb"))
		reverse_rotate(stack_b);
	if (!ft_strcmp(instruction, "rrr"))
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
}

static int	check_wrong_instruction(char *instruction)
{
	if (!ft_strcmp(instruction, "sa") || !ft_strcmp(instruction, "sb")
		|| !ft_strcmp(instruction, "ss") || !ft_strcmp(instruction, "pa")
		|| !ft_strcmp(instruction, "pb") || !ft_strcmp(instruction, "ra")
		|| !ft_strcmp(instruction, "rb") || !ft_strcmp(instruction, "rr")
		|| !ft_strcmp(instruction, "rra") || !ft_strcmp(instruction, "rrb")
		|| !ft_strcmp(instruction, "rrr"))
		return (1);
	else
		return (0);
}

int	run_instruction(char *instruction, t_list2 **stack_a, t_list2 **stack_b)
{
	if (!check_wrong_instruction(instruction))
		return (-1);
	if (!check_instruction(instruction, stack_a, stack_b))
		return (0);
	if (!ft_strcmp(instruction, "sa"))
		swap(stack_a);
	if (!ft_strcmp(instruction, "sb"))
		swap(stack_b);
	if (!ft_strcmp(instruction, "ss"))
	{
		swap(stack_a);
		swap(stack_b);
	}
	if (!ft_strcmp(instruction, "pa"))
		push(stack_b, stack_a);
	if (!ft_strcmp(instruction, "pb"))
		push(stack_a, stack_b);
	run_rotate(instruction, stack_a, stack_b);
	return (1);
}

char	**run_instruction_n_add_path(char *instruction, char **path,
								  t_list2 **stack_a, t_list2 **stack_b)
{
	char	**result_path;

	result_path = path;
	if (run_instruction(instruction, stack_a, stack_b))
		result_path = ft_add_str_and_free_str1(path, instruction);
	return (result_path);
}
