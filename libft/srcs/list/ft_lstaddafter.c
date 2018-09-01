/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddafter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:53:18 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/13 11:53:21 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "list.h"

void			ft_lstaddafter(t_lst *lst, t_lst *node)
{
	if (lst == NULL)
		return ;
	node->next = lst->next;
	lst->next = node;
}
