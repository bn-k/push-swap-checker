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
	if (i == 0)
		return (ave);
	return (ave / i);
}

void	shift(t_heap *heap, t_pile *stack)
{
	int	pushed;
	int	rev;
	//if (heap->verb)
	//	getchar();
	if (1 >= stack->quick.i[stack->quick.len - 1] && stack->quick.len > 0)
		stack->quick.len--;
	stack->quick.pivot = get_pivot(stack->pile, stack->quick.i[stack->quick.len - 1]);
	if (heap->verb)
	{
		ft_printf("=====================================NEW QUICK=================================\nCURRENT Stack= %c\n", stack->id);
		print_heap(heap);
		ft_printf("pivot= %d, len %d\n", stack->quick.pivot, stack->quick.i[stack->quick.len - 1]);
	}
	pushed = 0;
	rev = 0;
	while (pushed + rev < stack->quick.i[stack->quick.len -1])  // apply quick sort
	{
		if (0 >= stack->sort(stack->pile[0], stack->quick.pivot))
		{
			if (heap->verb)
				ft_printf("push %d\n", stack->pile[0]);
			exec_ope(stack->push, heap);
			pushed++;
		}
		else
		{
			if (heap->verb)
				ft_printf("rotate %d\n", stack->pile[0]);
			exec_ope(stack->rotate, heap);
			rev++;
		}
	}
	if (heap->verb)
	{
		ft_printf("rev + pushed = %d, len %d\n", rev + pushed, stack->quick.i[stack->quick.len -1]);
			ft_printf("Stack id %c\n", stack->id);
	}
	stack->other->quick.i[stack->other->quick.len] = pushed; //create quick sort
	stack->other->quick.len++; // add quick sort
	if (stack->quick.len > 1) // continue quick sort
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
		if (heap->verb)
		{
			ft_printf(">>>>>>>>continue quick<<<<<<<<<<<< turn = %d\n", heap->turn);
			ft_printf("to Stack %c\n", stack->id);
		}
		shift(heap, stack);
	}
	else if (stack->len > 2) // repeat quick sort
	{
		if (heap->verb)
		{
			ft_printf(">>>>>>>>repeat quick<<<<<<<<<<<< turn = %d\n", heap->turn);
			ft_printf("to Stack %c\n", stack->id);
		}
		stack->quick.i[0] = stack->len;
		stack->quick.len = 1;
		shift(heap, stack);
	}
	else if (heap->turn > 1) // Shift to other stack
	{
		heap->turn--;
		if (heap->verb)
			ft_printf(">>>>>>>>>>>>>>>SHIFT<<<<<<<<<<<<<<<<<<< turn = %d\n", heap->turn);
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
	heap->turn = 3;
	shift(heap, &heap->a);
}
