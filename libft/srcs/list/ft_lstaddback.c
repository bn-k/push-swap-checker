/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:53:33 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/13 11:55:11 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "list.h"
#include "libft.h"

void			ft_lstaddback(t_lst **alst, t_lst *node)
{
	t_lst		*lst;

	lst = *alst;
	if (lst == NULL)
		*alst = node;
	else
	{
		while (lst->next != NULL)
			lst = lst->next;
		lst->next = node;
	}
}
