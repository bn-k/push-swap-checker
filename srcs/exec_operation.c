#include "checker.h"
#define	END 2

static const t_ope g_ope[] =
{
	{"ss", &swap_both},
	{"sa", &swap_a},
	{"sb", &swap_b}
};

int	exec_operation_lst(t_lst *a, t_lst *ope)
{
	t_lst *b;
	t_lst *tmp;
	int	i;

	b = a;
	while (ope)
	{
		i = 0;
		while (i < END)
		{
			if (!ft_strcmp(g_ope[i].code_ope, (char *)ope->data))
			{
				a = g_ope[i].func_ope(a, b);
				i = END;
			}
			else if (i == END - 1)
			{
				ft_printf("Error\n");
				return(0);
			}
			i++;
		}
		tmp = ope;
		ope = ope->next;
		free(tmp);
	}
	return(end(a));
}

int	end(t_lst *a)
{
	t_lst *tmp;

	print_parsed(NULL, a);
	while (a)
	{
		tmp = a->next;
		if (tmp)
			if (deref((int*)a->data) > deref((int*)tmp->data))
			{
				ft_printf("KO\n");
				return(0);
			}
		tmp = a;
		a = a->next;
		free(tmp);
	}
	ft_printf("OK\n");
	return (0);
}
