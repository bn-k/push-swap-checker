/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 19:16:21 by abbenham          #+#    #+#             */
/*   Updated: 2018/08/21 19:05:41 by abbenham         ###   ########.fr       */
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

void		ft_quit(t_heap *heap)
{
	free(heap->a.push);
	free(heap->b.push);
	free(heap->a.rotate);
	free(heap->b.rotate);
	free(heap->a.reverse);
	free(heap->b.reverse);
	free(heap->a.swap);
	free(heap->b.swap);
	free(heap->a.pile);
	free(heap->b.pile);
	free(heap);
}

void		free_checker(char **prog)
{
	int i;

	i = 0;
	if (prog)
	{
		while (prog[i] != NULL)
		{
			free(prog[i]);
			i++;
		}
		free(prog);
	}
}
