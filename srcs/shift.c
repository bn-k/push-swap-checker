#include "push_swap.h"

void	init_b(t_stack *stack)
{		
	if ((deref((ft_lstlast(stack->a))->data)) < (deref(stack->a->data)))
	{
		exec_ope("rra", stack);
		exec_ope("pb", stack);
	}
	else
		exec_ope("pb", stack);
}

void	shift(t_stack *stack)
{
	while (stack->a)
	{
		if (deref(stack->a->data))
			ft_putendl("sb");
		stack->a = stack->a->next;
	}
}
