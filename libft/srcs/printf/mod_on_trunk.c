/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_variation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 13:07:29 by abbenham          #+#    #+#             */
/*   Updated: 2018/08/21 19:27:22 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	mod_math(t_body *body)
{
	body->len = 1;
	body->plus = 0;
	body->point = 0;
	body->space = 0;
	body->left = POS(body->width - body->len - body->fill) *\
			(body->dash ? 0 : 1);
	body->right = (body->width - body->len - body->fill) * body->dash;
}

int			mod_on_trunk(t_total *total, t_body *body)
{
	mod_math(body);
	trunk_integers("%", total, body);
	return (1);
}
