/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadditer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:53:52 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/13 11:55:13 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "list.h"

void			ft_lstadditer(t_lst **begin, t_lst **iterator, t_lst *node)
{
	if (*begin == NULL)
		*begin = node;
	else
		(*iterator)->next = node;
	*iterator = node;
}
