/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:15:15 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/04 17:48:31 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H 
# include "libft.h"
# define END 11
# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"
# define HALF_WAY_A (stack->len_a / 2)
# define ABS(x) (x < 0 ? -x : x)

typedef	struct	s_stack
{
	t_lst		*a;
	t_lst		*b;
	t_lst		*ope;
	int			len_a;
	int			len_b;
	int			min;
	int			min_i;
	int			max;
	int			max_i;
	int			first;
	int			last;
	int			pivot;
}				t_stack;

typedef struct	s_ope
{
	char		*code_ope;
	void		(*func_ope)(t_stack*);
	char		*name;
}				t_ope;

t_lst	*operation_parser(void);
t_lst	*chain_parser(int ac, char **av);

void	print_stack2(t_stack *stack);

int		checker(t_stack *stack);
int		exec_operation_checker(t_stack *stack);

void	exec_ope(char *code_ope, t_stack *stack);

int		stack_sorted(t_stack *stack);

void	init_b(t_stack *stack);
void	get_data(t_stack *stack);

void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_both(t_stack *stack);

void	push_a(t_stack *stack);
void	push_b(t_stack *stack);

void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rotate_both(t_stack *stack);

void	reverse_rotate_a(t_stack *stack);
void	reverse_rotate_b(t_stack *stack);
void	reverse_rotate_both(t_stack *stack);

static const t_ope g_ope[] =
{
	{"rra", &reverse_rotate_a, "reverse rotate a"},
	{"rrb", &reverse_rotate_b, "reverse rotate b"},
	{"rrr", &reverse_rotate_both, "reverse rotate both"},
	{"ra", &rotate_a, "rotate a"},
	{"rb", &rotate_b, "rotate b"},
	{"rr", &rotate_both, "rotate both"},
	{"pa", &push_a, "push a"},
	{"pb", &push_b, "push b"},
	{"ss", &swap_both, "swap both"},
	{"sa", &swap_a, "swap a"},
	{"sb", &swap_b, "swap b"}
};

#endif
