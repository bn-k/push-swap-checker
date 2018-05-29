/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 13:18:56 by abbenham          #+#    #+#             */
/*   Updated: 2018/05/29 15:06:12 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push_a(t_stack *stack)
{
	t_lst *tmp_b;
	t_lst *tmp_a;

	if (stack->b)
	{
		tmp_b = stack->b->next;
		tmp_a = stack->b;
		tmp_a->next = stack->a;
		stack->a = tmp_a;
		stack->b = tmp_b;
	}
}

void	push_b(t_stack *stack)
{
	t_lst *tmp_b;
	t_lst *tmp_a;

	if (stack->a)
	{
		tmp_a = stack->a->next;
		tmp_b = stack->a;
		tmp_b->next = stack->b;
		stack->b = tmp_b;
		stack->a = tmp_a;
	}
}
