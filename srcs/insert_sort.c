
#include "push_swap.h"

void	go_to(int *pile, int needle)
{
	int	i;

	i = 0;
	while (pile[i] != needle)
	{
		i++;
	}
}

void	print_clean(int *clean, int len)
{
	int	i;

	i = 0;
	ft_printf("Clean ");
	while (i < len)
	{
		ft_printf("%d ", clean[i]);
		i++;
	}
	ft_printf("\n");
}

int	get_closest(t_heap *heap, int needle, int *clean, int len, t_pile *from, t_pile *to)
{
	int	i;
	int	closest;
	int	flag;

	i = 0;
	closest = 0;
	print_heap(heap);
	print_clean(clean, len);
	while (0 < from->sort(needle, clean[i + 1]) || 0 > from->sort(needle, clean[i + 1]))
	{
	ft_printf("Inferieur! %d", (0 > from->sort(needle, clean[i])));
		i++;
	}
	ft_printf("\n");
	return (closest);
}

void	insert_sort(t_heap *heap, t_pile *from, t_pile *to)
{
	int *clean;
	int	closest;

	clean = NULL;
	print_heap(heap);
	while (from->len > 0)
	{
		if (to->len > 0)
		{
			if (clean)
				ft_memdel((void**)&clean);
			clean = pre_sort(heap, to->pile, to->len);
			closest = get_closest(heap, from->pile[0], clean, to->len, from, to);
		//	ft_printf("Closest of %d is %d\n", from->pile[0], closest);
			exec_ope(from->push, heap);
		}
		else
			exec_ope(from->push, heap);
	}
}
