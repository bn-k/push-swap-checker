#include "push_swap.h"

void	exec_ope(char *code_ope, t_stack *stack)
{
	int	i;

	i = 0;
	while (i < END)
	{
		if (!ft_strcmp(code_ope, g_ope[i].code_ope))
		{
			g_ope[i].func_ope(stack);
			ft_putendl(code_ope);
		}
		i++;
	}
}
