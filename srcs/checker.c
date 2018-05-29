#include "checker.h"
#include "get_next_line.h"

int	main(int ac, char **av)
{
	t_lst	*a;
	t_lst	*ope;

	if (!(a = chain_parser(ac, av)))
	{
		ft_printf("Wrong number of argument\n");
		return(0);
	}
	ope = operation_parser();
	print_parsed(ope, a);
	return(exec_operation_lst(a, ope));
}
