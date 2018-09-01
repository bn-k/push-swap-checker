/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:54:18 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/13 11:55:20 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "list.h"

t_lst			*ft_lstgetn(t_lst *lst, int index)
{
	while (lst != NULL && index > 0)
	{
		lst = lst->next;
		index--;
	}
	return (lst);
}
