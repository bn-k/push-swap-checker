#include "push_swap.h"
#include "get_next_line.h"

void	push_swap(t_stack *stack)
{
	get_info(stack);
	sort_easy(stack);
}

int	main(int ac, char **av)
{
	t_stack	stack;

	ft_bzero(&stack, sizeof(stack));
	if (!(stack.a = chain_parser(ac, av)))
		return(0);
	push_swap(&stack);
	return(0);
}
