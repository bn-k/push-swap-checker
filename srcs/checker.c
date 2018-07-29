/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:26:12 by abbenham          #+#    #+#             */
/*   Updated: 2018/07/29 15:51:54 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

char	**programme_read(void)
{
	char	*ope;
	char	**prog;
	int	i;

	prog = NULL;
	i = 0;
	while (get_next_line(0, &ope))
	{
		if (!(prog = tabcat(prog, ope, ++i)))
			return (NULL);
	}
	prog[i] = NULL;
	return (prog);
}

static int	browse_function(char *ope, int step, t_heap *heap)
{
	int	i;

	i = 0;
	while (i < END)
	{
		if (!ft_strcmp(g_ope[i].code_ope, ope))
		{
			g_ope[i].func_ope(heap);
			ft_printf("%s\n",ope);
			i = END;
		}
		else if (i == END - 1)
		{
			ft_printf("Error\n");
			return(0);
		}
		i++;
	}
	return (1);
}

void	execute_prog(char **prog, t_heap *heap)
{
	int	i;

	i = 0;
	while (i < heap->a.len)
	{
		if (i > 0)
			ft_printf(" ");
		ft_printf("%d", heap->a.pile[i++]);
	}
	ft_printf("\n");
	i = 0;
	while (prog[i])
	{
		browse_function(prog[i], i, heap);
		i++;
	}
	if (is_sorted(heap))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int main(int ac, char **av)
{
	char **prog;
	t_heap *heap;

	if (!(heap = parser(ac, av)))
	{
		ft_printf("usage: \n");
		return (0);
	}
	if (!(prog = programme_read()))
	{
		ft_printf("Malloc error: \n");
		return (0);
	}
	/*
	*/
	init_math(heap);
	execute_prog(prog, heap);
	return (0);
}
