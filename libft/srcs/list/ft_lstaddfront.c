/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddfront.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:53:48 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/13 11:53:49 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void			ft_lstaddfront(t_lst **alst, t_lst *node)
{
	node->next = *alst;
	*alst = node;
}
