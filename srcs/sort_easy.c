#include "push_swap.h"
#include "list.h"

void	push_next(t_stack *stack, t_next *next)
{
	get_next_min(stack, next);
	while (deref(stack->a->data) != next->min)
	{
		if (next->min_i <= HALF_WAY_A )
			exec_ope("ra", stack);
		else
			exec_ope("rra", stack);
	}
	exec_ope("pb", stack);
}

void	sort_easy(t_stack *stack)
{
	t_next next;

	next.min = stack->min;
	next.min_i = stack->min_i;
	while (!stack_sorted(stack))
		push_next(stack, &next);
	while (stack->b)
		exec_ope("pa", stack);
}
