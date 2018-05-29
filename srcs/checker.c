#include "checker.h"
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
	stack.ope = operation_parser();
	print_parsed(stack.ope, &stack);
	return(exec_operation_lst(&stack));
}
