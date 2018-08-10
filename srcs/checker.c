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

char		**programme_read(void)
{
	char	*ope;
	char	**prog;
	int	i;

	prog = NULL;
	i = 0;
	int gnl;
	while (1 == (gnl = get_next_line(0, &ope)))
	{
		if (!(prog = tabcat(prog, ope, ++i)))
		{
			return (NULL);
		}
		prog[i] = NULL;
	}
	//ft_printf("gnl = %d\n", gnl);
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
			ft_printf("Browse function: Error >%s<\n", ope);
			return(0);
		}
		i++;
	}
	return (1);
}

static int	execute_prog(char **prog, t_heap *heap)
{
	int	i;

	i = 0;
	i = 0;
	while (prog[i])
	{
		if (!browse_function(prog[i], i, heap))
			return (0);
		i++;
	}
	return (1);
}

int 		main(int ac, char **av)
{
	char **prog;
	t_heap *heap;
	int	i;

	i = 0;
	if (!(heap = parser(ac, av)))
	{
		ft_printf("Checker: Error\n");
		return (0);
	}
	init_math(heap);
	prog = programme_read();
	while (i < heap->a.len)
	{
		if (i > 0)
			ft_printf(" ");
		ft_printf("%d", heap->a.pile[i++]);
	}
	ft_printf("\n");
	if (prog)
		execute_prog(prog, heap);
	if (is_sorted(heap))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
