#include "push_swap.h"

#define PA(x) heap->a.pile[x]

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

void	small_sort(t_heap *heap)	
{
	if (heap->a.len == 2)
	{
		if (!is_sorted(heap))
			exec_ope("sa", heap);
	}
	else if (heap->a.len == 3)
		three_sort(heap);
	else
		insert_sort(heap, &heap->a, &heap->b, heap->a.len);
}
