/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttoarray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:56:18 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/13 11:56:19 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

void			**ft_lsttoarray(t_lst *lst)
{
	int			i;
	int			len;
	void		**arr;

	if (lst == NULL)
		return (NULL);
	len = ft_lstlen(lst);
	if (!(arr = (void **)malloc(sizeof(void *) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		arr[i] = lst->data;
		lst = lst->next;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
