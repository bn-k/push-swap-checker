#include "push_swap.h"
#include "get_next_line.h"

t_lst	*operation_parser(void)
{
	t_lst 	*ope;
	char	*buff;

	ope = NULL;
	while (get_next_line(0, &buff))
	{
		ft_lstpushback(&ope, (void*)ft_strdup(buff));
		ft_memdel((void**)&buff);
	}
	return (ope);
}
