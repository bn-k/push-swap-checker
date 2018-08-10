/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:26:32 by abbenham          #+#    #+#             */
/*   Updated: 2018/07/29 15:26:33 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	is_sorted(t_heap *heap)
{
	int	a;
	int	b;
	int	i;

	i = 0;
	b = 1;
	while (i < heap->a.len - 1)
	{
		if (heap->a.pile[i] > heap->a.pile[i + 1])
			return (0);
		i++;
	}
	return (1);
}
