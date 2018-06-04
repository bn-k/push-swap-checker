#include "push_swap.h"

int	increase(int x, int y)
{
	return (x - y);
}

int	decrease(int x, int y)
{
	return (y - x);
}

int	is_sorted(t_lst *lst, int(f)(int, int))
{
	while (lst->next)
	{
		if (0 < f(deref(lst->data), deref(lst->next->data)))
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	stack_sorted(t_stack *stack)
{
	int	a;
	int	b;

	a = 1;
	b = 1;
	if (stack->a)
		a = is_sorted(stack->a, increase);
	if (stack->b)
		b = is_sorted(stack->b, decrease);
	return (a && b);
}
