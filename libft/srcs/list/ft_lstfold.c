/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:54:10 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/13 11:55:18 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "list.h"

void			*ft_lstfold(t_lst *lst,
					void *(*f)(const void *data1, const void *data2))
{
	void		*res;

	if (lst == NULL)
		return (NULL);
	res = lst->data;
	lst = lst->next;
	while (lst != NULL)
	{
		res = (*f)(res, lst->data);
		lst = lst->next;
	}
	return (res);
}
