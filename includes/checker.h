#ifndef CHECKER_H
# define CHECKER_H
# include "libft.h"

typedef struct	s_ope
{
	char	*code_ope;
	t_lst	*(*func_ope)(t_lst*, t_lst*);
}		t_ope;

typedef	struct	s_stack
{
	t_lst	*a;
	t_lst	*b;
	t_lst	*ope;
}		t_stack;

t_lst	*operation_parser(void);
t_lst	*chain_parser(int ac, char **av);

void	print_parsed(t_lst *ope, t_lst *chain);
int	exec_operation_lst(t_lst *a, t_lst *ope);
int	end(t_lst *a);

t_lst	*swap_a(t_lst *a, t_lst *b);
t_lst	*swap_b(t_lst *a, t_lst *b);
t_lst	*swap_both(t_lst *a, t_lst *b);

#endif
