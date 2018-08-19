#include "push_swap.h"

#define PA(x) heap->a.pile[x]
#define NOTHING_TO_DO ;

void	three_sort(t_heap *heap)	
{
	if (PA(0) > PA(1) && PA(0) < PA(2) && PA(1) < PA(2))
		exec_ope("sa", heap);
	else if (PA(0) > PA(1) && PA(0) > PA(2) && PA(1) < PA(2))
		exec_ope("ra", heap);
	else if (PA(0) > PA(1) && PA(0) > PA(2) && PA(1) > PA(2))
	{
		exec_ope("sa", heap);
		exec_ope("rra", heap);
	}
	else if (PA(0) < PA(1) && PA(0) < PA(2) && PA(1) > PA(2))
	{
		exec_ope("sa", heap);
		exec_ope("ra", heap);
	}
	else if (PA(0) < PA(1) && PA(0) > PA(2) && PA(1) > PA(2))
		exec_ope("rra", heap);
}

void	unit_sort(t_heap *heap)	
{
	int pivot;

	pivot = get_pivot(heap->a.pile, heap->a.len);
	while (heap->a.len > 3)
	{
		if (heap->a.pile[0] > pivot)
		{
			exec_ope("pb", heap);
			if (heap->b.len > 1)
				if (heap->b.pile[0] < heap->b.pile[1])
				{
					exec_ope("sb", heap);
				}
		}
		else
			exec_ope("ra", heap);
	}
	three_sort(heap);
	insert_sort(heap, &heap->b, &heap->a, heap->b.len);
//	print_heap(heap);
}

void	small_sort(t_heap *heap)	
{
	if (heap->a.len == 1)
		NOTHING_TO_DO
	else if (heap->a.len == 2)
	{
		if (!is_sorted(heap))
			exec_ope("sa", heap);
	}
	else if (heap->a.len == 3)
		three_sort(heap);
	else if (heap->a.len > 3 && heap->a.len < 6)
		unit_sort(heap);
	else
	{
		quick_sort(heap, 1);
		insert_sort(heap, &heap->b, &heap->a, heap->b.len);
	}
}
