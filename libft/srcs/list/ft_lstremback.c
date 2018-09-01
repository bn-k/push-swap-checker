/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:56:11 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/13 11:56:13 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "list.h"

t_lst			*ft_lstremback(t_lst **alst)
{
	t_lst		*node;
	t_lst		*prev;

	if ((prev = *alst) == NULL)
		return (NULL);
	if ((node = prev->next) == NULL)
	{
		*alst = NULL;
		return (prev);
	}
	while (node->next != NULL)
	{
		prev = node;
		node = node->next;
	}
	prev->next = NULL;
	return (node);
}
