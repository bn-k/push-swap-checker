/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:55:43 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/13 11:55:45 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "list.h"

t_lst			*ft_lstmap(t_lst *lst, t_lst *(*f)(t_lst *node))
{
	t_lst		*new;
	t_lst		*iter;

	new = NULL;
	iter = NULL;
	while (lst != NULL)
	{
		ft_lstadditer(&new, &iter, (*f)(lst));
		lst = lst->next;
	}
	return (new);
}
