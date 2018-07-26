
#include "push_swap.h"

int	get_closest(t_pile *stack, int needle, t_heap *heap)
{
	int	i;
	int	ret;
	int	closest;


	if (heap->verb)
		ft_printf("Find of closest of %d\n", needle);
	i = 0;
	closest = stack->of;
	ret = 0;
	while (i < stack->len)
	{
		if (stack->pile[i] < closest && stack->oper(stack->pile[i], needle))
		{
			closest = stack->pile[i];
			ret = i;
		}
		i++;
	}
	if (heap->verb)
		ft_printf("Closest found %d\n", closest);
	return (ret);
}

void	to_closest(t_heap *heap, t_pile *from, t_pile *to)
{
	int	i_closest;
	int	i;

	i = 0;
	if (heap->verb)
	{
		ft_printf("=======================To closest========================\n");
		getchar();
	}
	i_closest = get_closest(to, from->pile[0], heap);
	if (heap->verb)
		ft_printf("Index of closest %d\n", i_closest);
	if (to->len - i_closest >= i_closest)
		while (i < i_closest)
		{
			exec_ope(to->rotate, heap);
			i++;
		}
	else
		while (i < to->len - i_closest)
		{
			exec_ope(to->reverse, heap);
			i++;
		}

	exec_ope(from->push, heap);
	if (heap->verb)
		print_heap(heap);
}

void	insert_sort(t_heap *heap, t_pile *from, t_pile *to)
{
	if (heap->verb)
	{
		ft_printf("=====================================INSERT=====================================\n");
		print_heap(heap);

	}
	while (from->len > 0)
		to_closest(heap, from, to);
}
