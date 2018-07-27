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
			if (heap->a.pile[j] == heap->a.pile[i] && j != i)
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
			if (!isdigit(s[i][j++]))
				return (-1);
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
	if (!(heap->a.pile = (int*)malloc(sizeof(int) * (heap->len + 1 ))))
		return (NULL);
	if (!(heap->b.pile = (int*)malloc(sizeof(int) * heap->len)))
		return (NULL);
	while (i < heap->len)
	{
		heap->a.pile[i] = ft_atoi(s[i]);
		i++;
	}
	if (-1 == (duplicate(heap)))
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
	heap = (t_heap*)malloc(sizeof(t_heap));
	if (-1 == (heap->len = string_checker(s)))
		return (NULL);
	if (!(heap->a.pile = (int*)malloc(sizeof(int) * (heap->len + 1))))
		return (NULL);
	if (!(heap->b.pile = (int*)malloc(sizeof(int) * heap->len)))
		return (NULL);
	while (i < heap->len)
	{
		heap->a.pile[i] = ft_atoi(s[i]);
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
