/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:55:33 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/13 11:55:34 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>

t_lst		*ft_lstlast(t_lst *lst)
{
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
