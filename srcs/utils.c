/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:26:57 by abbenham          #+#    #+#             */
/*   Updated: 2018/05/29 16:02:10 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_heap(t_heap *heap)
{
	int	i;

	i = 0;
	ft_printf("A: ");
	while (i < heap->a.len)
	{
		ft_printf("%d ", heap->a.pile[i]);
		i++;
	}
	ft_printf("\n");
	ft_printf("B: ");
	i = 0;
	while (i < heap->b.len)
	{
		ft_printf("%d ", heap->b.pile[i]);
		i++;
	}
	ft_printf("\n");
}

void	init_math(t_heap *heap)
{
	heap->turn = 3;
	heap->a.len = heap->len;
	heap->b.len = 0;
	heap->a.other = &heap->b;
	heap->b.other = &heap->a;
	heap->a.id= 'a';
	heap->b.id= 'b';
	heap->a.push = ft_strdup("pb");
	heap->b.push = ft_strdup("pa");
	heap->a.rotate = ft_strdup("ra");
	heap->b.rotate = ft_strdup("rb");
	heap->a.reverse= ft_strdup("rra");
	heap->b.reverse= ft_strdup("rrb");
	heap->a.sort = &increase;
	heap->b.sort = &decrease;
}
