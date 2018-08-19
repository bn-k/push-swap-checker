/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:26:53 by abbenham          #+#    #+#             */
/*   Updated: 2018/08/19 17:58:46 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_heap *heap)
{
	if (heap->a.len > 0)
	{
		to_down(&heap->b.pile, heap->b.len);
		heap->b.len++;
		heap->b.pile[0] = heap->a.pile[0];
		to_up(&heap->a.pile, heap->a.len);
		heap->a.len--;
	}
}

void	push_a(t_heap *heap)
{
	if (heap->b.len > 0)
	{
		to_down(&heap->a.pile, heap->a.len);
		heap->a.len++;
		heap->a.pile[0] = heap->b.pile[0];
		to_up(&heap->b.pile, heap->b.len);
		heap->b.len--;
	}
}
