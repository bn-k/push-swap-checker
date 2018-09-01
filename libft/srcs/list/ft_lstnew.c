/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:55:47 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/13 11:55:48 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

t_lst			*ft_lstnew(void *data)
{
	t_lst		*node;

	if (!(node = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}
