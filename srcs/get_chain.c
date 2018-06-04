#include "push_swap.h"

static t_lst	*chain_parser_two_arg(int ac, char **av)
{
	t_lst 	*lst;
	t_lst 	*tmp;
	int	*num;

	lst = ft_arraytolst((void**)ft_strsplit(av[1], ' '));
	tmp = lst;
	while (tmp)
	{
		num = (int *)malloc(sizeof(int));
		*num = ft_atoi(tmp->data);
		tmp->data = num;
		tmp = tmp->next;
	}
	return (lst);
}

static t_lst	*chain_parser_infinite_arg(int ac, char **av)
{
	t_lst 	*lst;
	t_lst 	*tmp;
	int	*num;

	lst = ft_arraytolst((void **)av);
	tmp = lst->next;
	free(lst);
	lst = tmp;
	while (tmp)
	{
		num = (int *)malloc(sizeof(int));
		*num = ft_atoi(tmp->data);
		tmp->data = num;
		tmp = tmp->next;
	}
	return (lst);
}

t_lst	*chain_parser(int ac, char **av)
{
	if (ac == 1)
		return(NULL);
	else if (ac == 2)
		return(chain_parser_two_arg(ac, av));
	else
		return(chain_parser_infinite_arg(ac, av));
}
