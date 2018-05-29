#ifndef CHECKER_H
# define CHECKER_H
# include "libft.h"

typedef	struct	s_stack
{
	t_lst	*a;
	t_lst	*b;
	t_lst	*ope;
}				t_stack;

typedef struct	s_ope
{
	char	*code_ope;
	void	(*func_ope)(t_stack*);
}				t_ope;

t_lst	*operation_parser(void);
t_lst	*chain_parser(int ac, char **av);

void	print_parsed(t_lst *ope, t_stack *stack);

int		exec_operation_lst(t_stack *stack);
int		end(t_stack *stack);

void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_both(t_stack *stack);

void	push_a(t_stack *stack);
void	push_b(t_stack *stack);

void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rotate_both(t_stack *stack);
#endif
