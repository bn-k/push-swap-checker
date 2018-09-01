/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:54:14 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/13 11:55:19 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "list.h"

t_lst			*ft_lstget(t_lst *lst, t_bool (*f)(t_lst *node, void *data),
					void *data)
{
	while (lst != NULL)
	{
		if ((*f)(lst, data))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
