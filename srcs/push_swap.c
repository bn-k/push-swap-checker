/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:26:57 by abbenham          #+#    #+#             */
/*   Updated: 2018/08/21 18:53:54 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			sorted(int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void		basic_quick_sort(long *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	int	temp;

	if (low < high)
	{
		pivot = low;
		i = low;
		j = high;
		while (i < j)
		{
			while (arr[i] <= arr[pivot] && i <= high)
				i++;
			while (arr[j] > arr[pivot] && j >= low)
				j--;
			if (i < j)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		temp = arr[j];
		arr[j] = arr[pivot];
		arr[pivot] = temp;
		basic_quick_sort(arr, low, j - 1);
		basic_quick_sort(arr, j + 1, high);
	}
}

void		push_swap(t_heap *heap)
{
	if (heap->a.len < 20)
	{
		small_sort(heap);
		slide(heap);
	}
	else
	{
		quick_sort(heap, 3);
		insert_sort(heap, &heap->b, &heap->a, heap->b.len);
		slide(heap);
	}
}

int			main(int ac, char **av)
{
	t_heap	*heap;

	if (ac == 1)
		return (0);
	if (!(heap = parser(ac, av)))
	{
		ft_printf("usage: ./push_swap [arg]\n");
		return (0);
	}
	init_math(heap);
	heap->verb = 0;
	if (heap->verb)
		getchar();
	push_swap(heap);
	if (heap->verb)
		print_heap(heap);
	ft_quit(heap);
	return (0);
}
