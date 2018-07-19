#include "push_swap.h"

int	get_pivot(int *heap, int last)
{
	int	ave;
	int	i;

	ave = 0;
	i = 0;
	while (i < last)
	{
		ave += heap[i];
		i++;
	}
	return (ave / i);
}

void	shift(t_heap *heap, t_pile *stack)
{
	int	i;
	int	pushed;
	int	rev;
	t_next	next;

	if (1 >= stack->quick.i[stack->quick.len - 1] && stack->quick.len > 0)
		stack->quick.len--;

	stack->quick.pivot = get_pivot(stack->pile, stack->quick.i[stack->quick.len - 1]);
	/*
	   ft_printf("CURRENT Stack= %c\n", stack->id);
	   print_heap(heap);
	   print_heap(heap);
	   ft_printf("pivot= %d, len %d\n", stack->quick.pivot, stack->quick.i[stack->quick.len - 1]);
	   getchar();
	   */
	pushed = 0;
	rev = 0;
	i = 0;
	while (i + pushed <= stack->quick.i[stack->quick.len -1]) 
	{
		if (0 > stack->sort(stack->pile[0], stack->quick.pivot))
		{
			exec_ope(stack->push, heap);
			pushed++;
		}
		else
		{
			exec_ope(stack->rotate, heap);
			rev++;
		}
		i++;
	}
	stack->other->quick.i[stack->other->quick.len] = pushed;
	stack->other->quick.len++;
	if (stack->quick.len > 1)
	{
		stack->other->quick.i[stack->other->quick.len] = rev;
		stack->other->quick.len++;
		while (rev > 0)
		{
			exec_ope(stack->reverse, heap);
			exec_ope(stack->push, heap);
			rev--;
		}
		stack->quick.len--;
		shift(heap, stack);
	}
	if (stack->len > 2)
	{
		stack->quick.i[0] = stack->len;
		stack->quick.len = 1;
		shift(heap, stack);
	}
	else if (--heap->turn >= 0)
	{
		/*
		for (int d = 0; d < stack->other->quick.len ; d++)
		{
			ft_putnbrl(stack->other->quick.i[d]);
		}
		getchar();
		*/
		shift(heap, stack->other);
	}
}

void	quick_sort(t_heap *heap)
{
	heap->a.quick.i = (int*)malloc(sizeof(int) * heap->len);
	heap->b.quick.i = (int*)malloc(sizeof(int) * heap->len);
	heap->a.quick.len = 1;
	heap->b.quick.len = 0;
	heap->a.quick.i[0] = heap->len;
	heap->turn = 2;
	shift(heap, &heap->a);
	/*
	*/
}
