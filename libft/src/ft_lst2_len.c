#include "libft.h"

int	ft_lst2_len(t_list2 *lst)
{
	int	count;

	lst = ft_lst2first(lst);
	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
