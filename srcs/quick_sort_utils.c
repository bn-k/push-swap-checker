/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 13:25:50 by abbenham          #+#    #+#             */
/*   Updated: 2018/08/19 15:30:10 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	get_pivot(long *heap, int last)
{
	int	ave;
	int	i;

	ave = 0;
	i = 0;
	while (i < last)
	{
		ave += heap[i];
		i++;
	}
	if (i == 0)
		return (ave);
	return (ave / i);
}
