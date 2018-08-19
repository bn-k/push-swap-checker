/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:27:17 by abbenham          #+#    #+#             */
/*   Updated: 2018/08/19 13:42:17 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_heap *heap)
{
	int tmp;

	if (heap->a.len > 1)
	{
		tmp = heap->a.pile[0];
		heap->a.pile[0] = heap->a.pile[1];
		heap->a.pile[1] = tmp;
	}
}

void	swap_b(t_heap *heap)
{
	int tmp;

	if (heap->b.len > 1)
	{
		tmp = heap->b.pile[0];
		heap->b.pile[0] = heap->b.pile[1];
		heap->b.pile[1] = tmp;
	}
}

void	swap_both(t_heap *heap)
{
	swap_a(heap);
	swap_b(heap);
}
