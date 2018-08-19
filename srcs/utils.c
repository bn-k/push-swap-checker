/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:26:57 by abbenham          #+#    #+#             */
/*   Updated: 2018/08/19 19:18:30 by abbenham         ###   ########.fr       */
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

int		increase(int a, int b)
{
	return (a - b);
}

int		decrease(int a, int b)
{
	return (b - a);
}

int		upper(int a, int b)
{
	return ((a > b ? 1 : 0));
}

int		lower(int a, int b)
{
	return ((a < b ? 1 : 0));
}
