/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushafter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:55:55 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/13 11:55:56 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "list.h"

t_lst			*ft_lstpushafter(t_lst *lst, void *data)
{
	t_lst		*node;

	if (lst == NULL || !(node = ft_lstnew(data)))
		return (NULL);
	node->next = lst->next;
	lst->next = node;
	return (node);
}
