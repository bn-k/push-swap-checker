/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:26:57 by abbenham          #+#    #+#             */
/*   Updated: 2018/05/29 16:02:10 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(int *arr, int len)
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

void	basic_quick_sort(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	int	temp;
	if(low < high) 
	{
		pivot = low; // select a pivot element
		i = low;
		j = high;
		while(i < j) 
		{
			while(arr[i] <= arr[pivot] && i <= high)
				i++;
			while(arr[j] > arr[pivot] && j >= low)
				j--;
			if(i < j) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		// when i >= j it means the j-th position is the correct position
		// of the pivot element, hence swap the pivot element with the
		// element in the j-th position
		temp = arr[j];
		arr[j] = arr[pivot];
		arr[pivot] = temp;
		// Repeat quicksort for the two sub-arrays, one to the left of j
		// and one to the right of j
		basic_quick_sort(arr, low, j-1);
		basic_quick_sort(arr, j+1, high);
	}
}

int	*pre_sort(t_heap *heap, int *tab, int len)
{
	int	i;
	int	*clean;

	i = 0;
	clean = (int*)malloc(sizeof(int) * len);
	while (i < len)
	{
		clean[i] = tab[i];
		i++;
	}
	basic_quick_sort(clean, 0, len-1);
	return (clean);
}

void	slide(t_heap *heap)
{
	int	*sorted;

	sorted = pre_sort(heap, heap->a.pile, heap->a.len);
	while (heap->a.pile[0] != sorted[0])
		exec_ope("rra", heap);
	free(sorted);
}

void	push_swap(t_heap *heap)
{
	quick_sort(heap);
	insert_sort(heap, &heap->b, &heap->a);
	slide(heap);
}

int main(int ac, char **av)
{
	t_heap *heap;
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
	return (0);
}
