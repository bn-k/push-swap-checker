#include "push_swap.h"

int	checker(t_stack *stack)
{
	t_lst *tmp;

	while (stack->a)
	{
		tmp = stack->a->next;
		if (tmp)
			if (deref((int*)stack->a->data) > deref((int*)tmp->data))
			{
				ft_printf("KO\n");
				return(0);
			}
		tmp = stack->a;
		stack->a = stack->a->next;
		free(tmp);
	}
	ft_printf("OK\n");
	return (0);
}

static int		browse_function(t_stack *stack, int step)
{
	t_lst *tmp;
	int	i;

	i = 0;
	while (i < END)
	{
		if (!ft_strcmp(g_ope[i].code_ope, (char *)stack->ope->data))
		{
			g_ope[i].func_ope(stack);
			ft_printf("=====================\n");
			ft_printf("%sAction: %s%s%s step: %d\n", KGRN, KRED, g_ope[i].name, KNRM, step);
			//print_stack(stack);
			i = END;
		}
		else if (i == END - 1)
		{
			ft_printf("Wrong operation: %s\n", (char *)stack->ope->data);
			return(0);
		}
		i++;
	}
	tmp = stack->ope;
	stack->ope = stack->ope->next;
	free(tmp);
	return (1);
}

int	exec_operation_checker(t_stack *stack)
{
	int	step;

	step = 0;
	while (stack->ope)
	{
		if (!browse_function(stack, step))
			return (0);
		step++;
	}
	return(checker(stack));
}
