/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:15:15 by abbenham          #+#    #+#             */
/*   Updated: 2018/08/19 17:26:38 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# include "libft.h"
# define PUSH_SWAP_H 
# define END 11
# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"
# define ABS(x) (x < 0 ? -x : x)

typedef struct	s_quick
{
	int	*i;
	int	len;
	int	pivot;
	int	last;
	int	new;
}		t_quick;

typedef struct	s_pile
{
	char			id;
	long int			*pile;
	int			len;
	struct s_pile		*other;
	char			*push;
	char			*rotate;
	char			*reverse;
	char			*swap;
	int			(*sort)(int, int);
	int			(*oper)(int, int);
	int			of;
	int			position;
	t_quick			quick;
}		t_pile;

typedef struct	s_heap
{
	t_pile	a;
	t_pile	b;
	int	len;
	int	min;
	int	turn;
	int	sorted;
	int	*clean;
	int	verb;
}		t_heap;

typedef struct	s_ope
{
	char		*code_ope;
	void		(*func_ope)(t_heap*);
	char		*name;
}				t_ope;

void	quick_sort(t_heap *heap, int turn);
int		get_pivot(long *heap, int last);
void	shift(t_heap *heap, t_pile *stack);

void	small_sort(t_heap *heap);

void	insert_sort(t_heap *heap, t_pile *from, t_pile *to, int limit);

t_heap	*parser(int ac, char **av);
void	print_heap(t_heap *heap);
void	init_math(t_heap *heap);

int	is_sorted(t_heap *heap);
int	increase(int x, int y);
int	decrease(int x, int y);
void	slide(t_heap *heap);

void	test(t_heap *heap);
void	to_up(long **heap, int len);
void	to_down(long **heap, int len);

void	swap_a(t_heap *heap);
void	swap_b(t_heap *heap);
void	swap_both(t_heap *heap);

void	push_a(t_heap *heap);
void	push_b(t_heap *heap);

void	rotate_a(t_heap *heap);
void	rotate_b(t_heap *heap);
void	rotate_both(t_heap *heap);

void	reverse_rotate_a(t_heap *heap);
void	reverse_rotate_b(t_heap *heap);
void	reverse_rotate_both(t_heap *heap);

int	exec_ope(char *code_ope, t_heap *heap);
void	basic_quick_sort(long *arr, int low, int high);
long	*pre_sort(t_heap *heap, long *tab, int len);
	
int	upper(int a, int b);
int	lower(int a, int b);

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
