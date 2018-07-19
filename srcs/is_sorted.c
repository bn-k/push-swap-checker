#include "push_swap.h"

int	increase(int x, int y)
{
	return (x - y);
}

int	decrease(int x, int y)
{
	return (y - x);
}

int	is_sorted(t_heap *heap)
{
	int	a;
	int	b;
	int	i;

	i = 0;
	b = 1;
	while (i < heap->a.len - 1)
	{
		if (heap->a.pile[i] > heap->a.pile[i + 1])
			return (0);
		i++;
	}
	return (1);
}
