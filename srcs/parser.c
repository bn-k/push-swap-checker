/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:26:48 by abbenham          #+#    #+#             */
/*   Updated: 2018/08/19 19:06:14 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	duplicate(t_heap *heap)
{
	int	i;
	int	j;

	i = 0;
	while (i < heap->len)
	{
		j = 0;
		while (j < heap->len)
		{
			if ((heap->a.pile[j] == heap->a.pile[i] && j != i) ||\
					heap->a.pile[i] > INT_MAX || heap->a.pile[i] < INT_MIN)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

static int	string_checker(char **s)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (isdigit(s[i][j]) || s[i][j] == '-')
				;
			else
			{
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (i);
}

static t_heap	*parser_two_arg(int ac, char **av)
{
	t_heap *heap;
	char	**s;
	int	i;

	i = 0;
	s = ft_strsplit(av[1], ' ');
	heap = (t_heap*)malloc(sizeof(t_heap));
	if (-1 == (heap->len = string_checker(s)))
		return (NULL);
	if (!(heap->a.pile = (long*)malloc(sizeof(long) * (heap->len + 1))))
		return (NULL);
	if (!(heap->b.pile = (long*)malloc(sizeof(long) * heap->len)))
		return (NULL);
	while (i < heap->len)
	{
		heap->a.pile[i] = ft_atoi_long(s[i]);
		i++;
	}
	if (-1 == (duplicate(heap)) || heap->len < 1)
		return (NULL);
	return (heap);
}

static t_heap	*parser_infinite_arg(int ac, char **av)
{
	t_heap *heap;
	char **s;
	int	i;

	i = 0;
	s = &av[1];
	heap = (t_heap*)malloc(sizeof(t_heap) + 200);
	if (-1 == (heap->len = string_checker(s)))
		return (NULL);
	if (!(heap->a.pile = (long*)malloc(sizeof(long) * (heap->len + 1))))
		return (NULL);
	if (!(heap->b.pile = (long*)malloc(sizeof(long) * heap->len)))
		return (NULL);
	while (i < heap->len)
	{
		heap->a.pile[i] = ft_atoi_long(s[i]);
		i++;
	}
	if (-1 == (duplicate(heap)))
		return (NULL);
	return (heap);
}

t_heap	*parser(int ac, char **av)
{
	if (ac == 1)
		return(NULL);
	else if (ac == 2)
		return (parser_two_arg(ac, av));
	else
		return (parser_infinite_arg(ac, av));
}
