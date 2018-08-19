/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 19:16:21 by abbenham          #+#    #+#             */
/*   Updated: 2018/08/19 19:40:49 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_math(t_heap *heap)
{
	heap->turn = 3;
	heap->a.len = heap->len;
	heap->b.len = 0;
	heap->a.other = &heap->b;
	heap->b.other = &heap->a;
	heap->a.id = 'a';
	heap->b.id = 'b';
	heap->a.push = ft_strdup("pb");
	heap->b.push = ft_strdup("pa");
	heap->a.rotate = ft_strdup("ra");
	heap->b.rotate = ft_strdup("rb");
	heap->a.reverse = ft_strdup("rra");
	heap->b.reverse = ft_strdup("rrb");
	heap->a.swap = ft_strdup("sa");
	heap->b.swap = ft_strdup("sb");
	heap->a.sort = &increase;
	heap->b.sort = &decrease;
	heap->a.position = 0;
	heap->b.position = 1;
	heap->a.oper = upper;
	heap->b.oper = lower;
	heap->a.of = INT_MAX;
	heap->b.of = INT_MIN;
}
