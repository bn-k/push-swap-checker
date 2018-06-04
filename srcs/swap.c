/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 13:19:20 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/04 17:42:16 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack)
{
	t_lst	*beg;

	if (stack->a)
		if (stack->a->next)
		{
			beg = stack->a->next;;
			stack->a->next = stack->a->next->next;
			beg->next = stack->a;
			stack->a = beg;
		}
}

void	swap_b(t_stack *stack)
{
	t_lst	*beg;

	if (stack->b)
		if (stack->b->next)
		{
			beg = stack->b->next;;
			stack->b->next = stack->b->next->next;
			beg->next = stack->b;
			stack->b = beg;
		}
}

void	swap_both(t_stack *stack)
{
	swap_a(stack);
	swap_b(stack);
}
