#include "push_swap.h"
#include "get_next_line.h"

int	main(int ac, char **av)
{
	t_stack	stack;

	ft_bzero(&stack, sizeof(stack));
	if (!(stack.a = chain_parser(ac, av)))
	{
		ft_printf("Wrong number of argument\n");
		return(0);
	}
	print_stack2(&stack);
	ft_putchar('\n');
	stack.ope = operation_parser();
	return(exec_operation_checker(&stack));
}
