/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraytolst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:53:00 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/13 11:53:15 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

t_lst			*ft_arraytolst(void **arr)
{
	t_lst		*lst;
	t_lst		*iter;

	lst = NULL;
	iter = NULL;
	while (*arr != NULL)
	{
		if (!ft_lstpushiter(&lst, &iter, *arr))
			return (NULL);
		arr++;
	}
	return (lst);
}
