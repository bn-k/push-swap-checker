/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushby.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:56:01 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/13 11:56:03 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "list.h"

t_lst			*ft_lstpushby(t_lst **alst, void *data,
					int (*cmp)(const void *data1, const void *data2))
{
	t_lst		*node;

	if (!(node = ft_lstnew(data)))
		return (NULL);
	ft_lstaddby(alst, node, cmp);
	return (node);
}
