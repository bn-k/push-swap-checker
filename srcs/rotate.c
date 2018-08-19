/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:27:12 by abbenham          #+#    #+#             */
/*   Updated: 2018/08/19 14:29:13 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_heap *heap)
{
	int	first;

	if (heap->a.len > 1)
	{
		first = heap->a.pile[0];
		to_up(&heap->a.pile, heap->a.len);
		heap->a.pile[heap->a.len - 1] = first;
	}
}

void	rotate_b(t_heap *heap)
{
	int	first;

	if (heap->b.len > 1)
	{
		first = heap->b.pile[0];
		to_up(&heap->b.pile, heap->b.len);
		heap->b.pile[heap->b.len - 1] = first;
	}
}

void	rotate_both(t_heap *heap)
{
	rotate_a(heap);
	rotate_b(heap);
}
