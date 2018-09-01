/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:55:58 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/13 11:56:00 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "list.h"
#include "libft.h"

t_lst			*ft_lstpushback(t_lst **alst, void *data)
{
	t_lst		*node;

	if (!*alst)
	{
		*alst = ft_lstnew(data);
		return (*alst);
	}
	if (!(node = ft_lstnew(data)))
		return (NULL);
	ft_lstaddback(alst, node);
	return (node);
}
