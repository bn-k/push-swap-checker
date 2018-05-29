#include "checker.h"
#include "list.h"

void	print_parsed(t_lst *ope, t_lst *chain)
{
	printf("%s %s %s\n", "=", "Print Parsed", "=");
	printf("%s %s %s\n", "======", "chain", "===");
	ft_lstprintnb(chain);
	printf("%s %s %s\n", "==", "operation", "===");
	ft_lstprintstr(ope);
}
