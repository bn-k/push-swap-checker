#include "push_swap.h"
#include "list.h"

void	print_lst(t_lst *lst)
{
	int	i;

	i = 0;
	if (lst)
	while (lst)
	{
		if (i == 0)
			ft_printf("%d", deref((int*)lst->data));
		if (i > 0)
			ft_printf(" %d", deref((int*)lst->data));
		lst = lst->next;
		i++;
	}
}

void	print_stack2(t_stack *stack)
{
	print_lst(stack->a);
//	ft_putchar('\n');
//	print_lst(stack->b);
}

void	print_stack(t_stack *stack)
{
	t_lst *a;
	t_lst *b;
	int		nba;
	int		nbb;
	int		i = 1;

	a = stack->a;
	b = stack->b;
	while (a || b)
	{
		i = 0;
		if (a)
		{
			nba = deref((int*)a->data);
			a = a->next;
			i = 1;
		}
		if (b)
		{
			nbb = deref((int*)b->data);
			b = b->next;
			i = i + 10;
		}
		if (i == 11)
			ft_printf(" %10i  %i\n", nba, nbb);
		if (i == 1)
			ft_printf(" %10i\n", nba);
		if (i == 10)
			ft_printf(" %13i\n", nbb);
	}
}
