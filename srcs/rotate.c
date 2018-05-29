/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:26:57 by abbenham          #+#    #+#             */
/*   Updated: 2018/05/29 16:02:10 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate_a(t_stack *stack)
{
	t_lst	*tmp;
	t_lst	*tracker;

	tracker = stack->a;
	while (tracker->next)
		tracker = tracker->next;
	tmp = stack->a;
	stack->a = stack->a->next;
	tracker->next = tmp;
	tracker->next->next = NULL;
} 

void	rotate_b(t_stack *stack)
{
	t_lst	*tmp;
	t_lst	*tracker;

	tracker = stack->b;
	while (tracker->next)
		tracker = tracker->next;
	tmp = stack->b;
	stack->b = stack->b->next;
	tracker->next = tmp;
	tracker->next->next = NULL;
} 

void	rotate_both(t_stack *stack)
{
	rotate_a(stack);
	rotate_b(stack);
} 
