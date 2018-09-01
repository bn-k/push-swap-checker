/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:54:05 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/13 11:55:17 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "list.h"

t_lst			*ft_lstdup(t_lst *lst)
{
	t_lst		*cpy;
	t_lst		*iter;

	cpy = NULL;
	iter = NULL;
	while (lst != NULL)
	{
		if (!(ft_lstpushiter(&cpy, &iter, lst->data)))
			return (NULL);
		lst = lst->next;
	}
	return (cpy);
}
