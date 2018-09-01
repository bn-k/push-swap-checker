/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushiter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:56:08 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/13 11:56:10 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "list.h"

t_lst			*ft_lstpushiter(t_lst **begin, t_lst **iterator, void *data)
{
	t_lst		*node;

	if (!(node = ft_lstnew(data)))
		return (NULL);
	if (*begin == NULL)
		*begin = node;
	else
		(*iterator)->next = node;
	*iterator = node;
	return (node);
}
