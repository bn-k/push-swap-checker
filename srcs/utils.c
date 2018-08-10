/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:26:57 by abbenham          #+#    #+#             */
/*   Updated: 2018/07/29 15:28:18 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

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

int	increase(int a, int b)
{
	return (a - b);
}

int	decrease(int a, int b)
{
	return (b - a);
}

int	upper(int a, int b)
{
	return ((a > b ? 1 : 0));
}

int	lower(int a, int b)
{
	return ((a < b ? 1 : 0));
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
	heap->a.swap= ft_strdup("sa");
	heap->b.swap= ft_strdup("sb");
	heap->a.sort = &increase;
	heap->b.sort = &decrease;
	heap->a.position= 0;
	heap->b.position= 1;
	heap->a.oper = upper;
	heap->b.oper = lower;
	heap->a.of = INT_MAX;
	heap->b.of = INT_MIN;
}
