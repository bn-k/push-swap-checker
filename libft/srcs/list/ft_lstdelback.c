/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:54:01 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/13 11:55:16 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

void			ft_lstdelback(t_lst **alst, void (*del)(void *data))
{
	t_lst		*node;

	if ((node = ft_lstremback(alst)))
	{
		if (del)
			(*del)(node->data);
		free(node);
	}
}
