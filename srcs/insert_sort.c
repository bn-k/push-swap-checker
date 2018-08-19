/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:26:24 by abbenham          #+#    #+#             */
/*   Updated: 2018/08/19 19:40:18 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_closest(t_pile *stack, int needle, t_heap *heap)
{
	int	i;
	int	ret;
	int	closest;

	i = 0;
	closest = stack->of;
	ret = 0;
	while (i < stack->len)
	{
		if (stack->pile[i] < closest && stack->pile[i] > needle)
		{
			closest = stack->pile[i];
			ret = i;
		}
		i++;
	}
	return (ret);
}

void	insert(t_heap *heap, t_pile *from, t_pile *to)
{
	int	i_closest;
	int	i;

	i = 0;
	i_closest = get_closest(to, from->pile[0], heap);
	if (to->len - i_closest >= i_closest)
		while (i < i_closest)
		{
			exec_ope(to->rotate, heap);
			i++;
		}
	else
		while (i < to->len - i_closest)
		{
			exec_ope(to->reverse, heap);
			i++;
		}
	exec_ope(from->push, heap);
}

void	insert_sort(t_heap *heap, t_pile *from, t_pile *to, int limit)
{
	while (from->len > 0)
		insert(heap, from, to);
}
