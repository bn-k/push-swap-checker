/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddby.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:53:44 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/13 11:53:46 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "list.h"

void			ft_lstaddby(t_lst **alst, t_lst *node,
					int (*f)(const void *, const void *))
{
	t_lst		*lst;
	t_lst		*lst_prev;

	lst = *alst;
	lst_prev = NULL;
	while (lst != NULL && (*f)(node->data, lst->data) <= 0)
	{
		lst_prev = lst;
		lst = lst->next;
	}
	if (lst_prev != NULL)
		ft_lstaddafter(lst_prev, node);
	else
		ft_lstaddfront(alst, node);
}
