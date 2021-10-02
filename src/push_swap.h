#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/src/libft.h"

# ifndef PRINT_CHECK
#  define PRINT_CHECK 0
# endif

# ifndef PRINT_ALL
#  define PRINT_ALL 0
# endif

# ifndef USE_MAX_SORT
#  define USE_MAX_SORT 0
# endif

typedef struct s_rotate
{
	int	ra;
	int	rb;
}	t_rotate;

typedef struct s_push_swap
{
	int		number_items;
	char	**shotest_path;
	t_list2	*stack_a;
	char	*algorithm;
	int		cur_item;
	int		sort_pos1;
	int		sort_pos2;
	int		round;
}	t_push_swap;

/*
** push_swap_instructions
*/

void		swap(t_list2 **stack);

void		push(t_list2 **stack_src, t_list2 **stack_dst);

void		rotate(t_list2 **stack);

void		reverse_rotate(t_list2 **stack);

/*
** push_swap_utils
*/

int			is_stack_sorted(t_list2 *stack);

t_list2		*stack_copy(t_list2 *stack);

int			run_instruction(char *instruction, t_list2 **stack_a,
				t_list2 **stack_b);

void		*free_stacks(t_list2 **stack_a, t_list2 **stack_b, int *num);

void		min_n_max_item(t_list2 *stack, int *min, int *max);

void		go_to_min(char ***path_to_sort, t_list2 **stack_a);

void		go_to_max(char ***path_to_sort, t_list2 **stack_b);

int			find_pos(int nomber, t_list2 *stack);

int			max(int num1, int num2);

int			init_pswp(t_push_swap *pswp, char **argv);

/*
** error_manegment.c
*/

int			free_pswp(t_push_swap *pswp);

int			check_stack_a(t_list2 *stack_a, int *item);

void		*print_error(t_list2 **stack_a, t_list2 **stack_b, int *num);

void		*error_check(t_list2 **stack_a, t_list2 **stack_b, int *num);

/*
** run_commands
*/

char		**run_instruction_n_add_path(char *instruction, char **path,
				t_list2 **stack_a, t_list2 **stack_b);

/*
** print_functions
*/

void		print_stack(char *prefix, t_list2 *stack, char *post_str);

/*
** algorithms
*/

char		**first_check(t_push_swap *pswp);

char		**buble_sort(t_push_swap *pswp);

char		**insertion_sort(t_push_swap *pswp);

char		**_insertion_sort(t_list2 *stack_a, t_list2 *stack_b);

char		**insertion_sort_extended(t_push_swap *pswp);

t_rotate	minimum_rotate(int ra, int rra, int rb, int rrb);

int			find_pos_in_stack_a(t_list2 *stack_a, int num);

char		**first_sort_ise(t_list2 **stack_a, t_list2 **stack_b);

char		**do_rotate_optimisation_ise(t_rotate *number_actions,
				t_list2 **stack_a, t_list2 **stack_b, char **sort_path);

t_rotate	*get_number_actions(t_list2 *stack_a, t_list2 *stack_b);

int			find_medium_item(t_list2 *stack_a);

#endif
