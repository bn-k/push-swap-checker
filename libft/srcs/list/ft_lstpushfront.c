/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:56:05 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/13 11:56:06 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "list.h"

t_lst			*ft_lstpushfront(t_lst **alst, void *data)
{
	t_lst		*node;

	if (!(node = ft_lstnew(data)))
		return (NULL);
	ft_lstaddfront(alst, node);
	return (node);
}
