#include "checker.h"
#define	END 7

static const t_ope g_ope[] =
{
	{"ra", &rotate_a},
	{"rb", &rotate_b},
	{"rr", &rotate_both},
	{"pa", &push_a},
	{"pb", &push_b},
	{"ss", &swap_both},
	{"sa", &swap_a},
	{"sb", &swap_b}
};

static int		browse_function(t_stack *stack)
{
	t_lst *tmp;
	int	i;

	i = 0;
	while (i < END)
	{
		if (!ft_strcmp(g_ope[i].code_ope, (char *)stack->ope->data))
		{
			g_ope[i].func_ope(stack);
			i = END;
		}
		else if (i == END - 1)
		{
			ft_printf("Error\n");
			return(0);
		}
		i++;
	}
	tmp = stack->ope;
	stack->ope = stack->ope->next;
	free(tmp);
	return (1);
}

int	exec_operation_lst(t_stack *stack)
{
	int	i;

	while (stack->ope)
		if (!browse_function(stack))
			return (0);
	return(end(stack));
}

int	end(t_stack *stack)
{
	t_lst *tmp;

	print_parsed(NULL, stack);
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
