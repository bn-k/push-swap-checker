/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:27:01 by abbenham          #+#    #+#             */
/*   Updated: 2018/08/21 18:57:35 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		iteration(t_heap *heap, t_pile *stack)
{
	int	pushed;
	int	rev;

	if (1 >= stack->quick.i[stack->quick.len - 1] && stack->quick.len > 0)
		stack->quick.len--;
	stack->quick.pivot = get_pivot(stack->pile,\
			stack->quick.i[stack->quick.len - 1]);
	pushed = 0;
	rev = 0;
	while (pushed + rev < stack->quick.i[stack->quick.len - 1])
	{
		if (0 >= stack->sort(stack->pile[0], stack->quick.pivot))
			pushed += exec_ope(stack->push, heap);
		else
			rev += exec_ope(stack->rotate, heap);
	}
	stack->other->quick.i[stack->other->quick.len] = pushed;
	stack->other->quick.len++;
	return (rev);
}

int		continue_quick_sort(t_heap *heap, t_pile *stack, int rev)
{
	stack->other->quick.i[stack->other->quick.len] = rev;
	stack->other->quick.len++;
	while (rev > 0)
	{
		rev -= exec_ope(stack->reverse, heap);
		exec_ope(stack->push, heap);
	}
	stack->quick.len--;
	shift(heap, stack);
	return (rev);
}

void	repeat_quick_sort(t_heap *heap, t_pile *stack)
{
	stack->quick.i[0] = stack->len;
	stack->quick.len = 1;
	shift(heap, stack);
}

void	shift(t_heap *heap, t_pile *stack)
{
	int rev;

	rev = iteration(heap, stack);
	if (stack->quick.len > 1)
		rev = continue_quick_sort(heap, stack, rev);
	else if (stack->len > 2)
		repeat_quick_sort(heap, stack);
	else if (heap->turn > 1)
	{
		heap->turn--;
		shift(heap, stack->other);
	}
}

void	quick_sort(t_heap *heap, int turn)
{
	heap->a.quick.i = (int*)malloc(sizeof(int) * heap->len);
	heap->b.quick.i = (int*)malloc(sizeof(int) * heap->len);
	heap->a.quick.len = 1;
	heap->b.quick.len = 0;
	heap->a.quick.i[0] = heap->len;
	heap->turn = turn;
	shift(heap, &heap->a);
	free(heap->a.quick.i);
	free(heap->b.quick.i);
}
