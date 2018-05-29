#include "checker.h"

t_lst	*swap_a(t_lst *a, t_lst *b)
{
	(void)b;
	t_lst	*beg;

	beg = a->next;;
	a->next = a->next->next;
	beg->next = a;
	a = beg;
	return (beg);
}

t_lst	*swap_b(t_lst *a, t_lst *b)
{
	(void)a;
	t_lst	*beg;

	beg = b->next;;
	b->next = b->next->next;
	beg->next = b;
	b = beg;
	return (beg);
}

t_lst	*swap_both(t_lst *a, t_lst *b)
{

	return (a);
}
