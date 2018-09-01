/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:55:51 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/13 11:55:52 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "list.h"

int	deref(int *nb)
{
	return (*nb);
}

int	ft_lstprintnb(t_lst *lst)
{
	int	i;
	int	nb;

	i = 0;
	while (lst)
	{
		nb = deref((int*)lst->data);
		ft_putnbrl(nb);
		lst = lst->next;
		i++;
	}
	return (i);
}

int	ft_lstprintstr(t_lst *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		ft_putendl((char *)lst->data);
		lst = lst->next;
		i++;
	}
	return (i);
}
