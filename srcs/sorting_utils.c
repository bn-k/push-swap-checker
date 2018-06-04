#include "push_swap.h"

void	get_info(t_stack *stack)
{
	t_lst	*lst;
	int	min;
	int	max;

	lst = stack->a;
	min = 2147483647;
	max = -2147483648;
	stack->len_b = 0;
	while (lst)
	{
		if (min > deref(lst->data))
		{
			min = deref(lst->data);
			stack->min_i = stack->len_a;
		}
		if (max < deref(lst->data))
		{
			max = deref(lst->data);
			stack->max_i = stack->len_a;
		}
		lst=lst->next;
		stack->len_a++;
	}
	stack->min = min;
	stack->max = max;
	stack->pivot = max - (max - min) / 2;
}

void	get_next_min(t_stack *stack, t_next *next)
{
	t_lst	*lst;

	lst = stack->a;
	next->min = 2147483647;
	next->min_i = 0;
	while (lst)
	{
		if (next->min > deref(lst->data))
		{
			next->min = deref(lst->data);
			next->min_i++;
		}
		lst = lst->next;
	}
}
