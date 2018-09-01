/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kitchen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:02:03 by abbenham          #+#    #+#             */
/*   Updated: 2018/03/08 17:02:23 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	trunk(char *s, t_total *total, t_body *body)
{
	int		i;

	i = 0;
	while (i < body->left)
	{
		charcat(body->zero ? '0' : ' ', total);
		i++;
	}
	i = 0;
	while (i < body->len)
	{
		charcat(s[i], total);
		i++;
	}
	i = 0;
	while (i < body->right)
	{
		charcat(' ', total);
		i++;
	}
}
