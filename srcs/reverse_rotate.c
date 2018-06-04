/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:26:57 by abbenham          #+#    #+#             */
/*   Updated: 2018/05/29 16:02:10 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack *stack)
{
	t_lst	*tmp;
	t_lst	*tracker;
	if (stack->a)
	{
		tracker = stack->a;
		while (tracker->next)
		{
			tmp = tracker;
			tracker = tracker->next;
		}
		tracker->next = stack->a;
		stack->a = tracker;
		tmp->next = NULL;
	}	
} 

void	reverse_rotate_b(t_stack *stack)
{
	t_lst	*tmp;
	t_lst	*tracker;

	if (stack->b)
	{
		tracker = stack->b;
		while (tracker->next)
		{
			tmp = tracker;
			tracker = tracker->next;
		}
		tracker->next = stack->b;
		stack->b = tracker;
		tmp->next = NULL;
	}	
} 

void	reverse_rotate_both(t_stack *stack)
{
	reverse_rotate_a(stack);
	reverse_rotate_b(stack);
} 
