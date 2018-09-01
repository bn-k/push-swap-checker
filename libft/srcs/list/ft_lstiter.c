/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:55:30 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/13 11:55:31 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "list.h"

void			ft_lstiter(t_lst *lst, void (*f)(t_lst *node))
{
	while (lst != NULL)
	{
		(*f)(lst);
		lst = lst->next;
	}
}
