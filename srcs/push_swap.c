/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:26:57 by abbenham          #+#    #+#             */
/*   Updated: 2018/08/22 10:57:34 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap_quick_sort(int i, int j, long **arr)
{
	int	temp;

	if (i < j)
	{
		temp = arr[0][i];
		arr[0][i] = arr[0][j];
		arr[0][j] = temp;
	}
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
			swap_quick_sort(i, j, &arr);
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

	if (!(heap = parser(ac, av)) || ac == 1)
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
