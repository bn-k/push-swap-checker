/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slide.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 14:45:18 by abbenham          #+#    #+#             */
/*   Updated: 2018/08/19 17:42:10 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_index_of_min(t_heap *heap)
{
	int	i;
	long min;
	int index_of_min;

	min = INT_MAX;
	i = 0;
	while (i < heap->a.len)
	{
		if (heap->a.pile[i] < min)
		{
			min = heap->a.pile[i];
			index_of_min = i;
		}
		i++;
	}
	return (index_of_min);
}

long	*pre_sort(t_heap *heap, long *tab, int len)
{
	int	i;
	long	*clean;

	i = 0;
	clean = (long*)malloc(sizeof(long) * len);
	while (i < len)
	{
		clean[i] = tab[i];
		i++;
	}
	basic_quick_sort(clean, 0, len-1);
	return (clean);
}

void	slide(t_heap *heap)
{
	long *sorted;
	int		index_of_min;
	int		i;

	i = 0;

	sorted = pre_sort(heap, heap->a.pile, heap->a.len);
	index_of_min = get_index_of_min(heap);
	if (index_of_min < heap->a.len / 2 + 1)
		while (i++ < index_of_min)
			exec_ope("ra", heap);
	else
		while (heap->a.pile[0] != sorted[0])
			exec_ope("rra", heap);
	free(sorted);
}

