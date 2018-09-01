/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetprev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:55:25 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/13 11:55:26 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "list.h"

t_lst			*ft_lstgetprev(t_lst *lst, t_bool (*f)(t_lst *node, void *data),
					void *data, t_lst **prev)
{
	if (!lst)
	{
		*prev = NULL;
		return (NULL);
	}
	if ((*f)(lst, data))
	{
		*prev = NULL;
		return (lst);
	}
	while (lst->next && !(*f)(lst->next, data))
		lst = lst->next;
	*prev = lst;
	return (lst->next);
}
