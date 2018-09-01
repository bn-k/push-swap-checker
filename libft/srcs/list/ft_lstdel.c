/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:53:56 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/13 11:55:15 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

void			ft_lstdel(t_lst **alst, void (*del)(void *data))
{
	t_lst		*lst;
	t_lst		*next;

	lst = *alst;
	while (lst != NULL)
	{
		next = lst->next;
		if (del)
			(*del)(lst->data);
		free(lst);
		lst = next;
	}
	*alst = NULL;
}
