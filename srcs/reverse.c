/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:27:06 by abbenham          #+#    #+#             */
/*   Updated: 2018/07/29 15:27:08 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_heap *heap)
{
	int	last;

	if (heap->a.len > 1)
	{
		last = heap->a.pile[heap->a.len - 1];
		to_down(&heap->a.pile, heap->a.len);
		heap->a.pile[0] = last;
	}
}

void	reverse_rotate_b(t_heap *heap)
{
	int	last;

	if (heap->b.len > 1)
	{
		last = heap->b.pile[heap->b.len - 1];
		to_down(&heap->b.pile, heap->b.len);
		heap->b.pile[0] = last;
	}
}

void	reverse_rotate_both(t_heap *heap)
{
	reverse_rotate_a(heap);
	reverse_rotate_b(heap);
}
