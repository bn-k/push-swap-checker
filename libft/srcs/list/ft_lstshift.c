/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstshift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:56:14 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/13 11:56:16 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

void			ft_lstshift(t_lst **alst, void (*del)(void *data))
{
	t_lst		*lst;
	t_lst		*next;

	lst = *alst;
	if (lst == NULL)
		return ;
	next = lst->next;
	if (del)
		(*del)(lst->data);
	free(lst);
	*alst = next;
}
