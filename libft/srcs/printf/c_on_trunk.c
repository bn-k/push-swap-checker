/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_variation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 13:07:29 by abbenham          #+#    #+#             */
/*   Updated: 2018/03/08 17:17:54 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	c_math(t_body *body)
{
	body->len = 1;
	body->left = (body->width - 1) * (body->dash ? 0 : 1);
	body->right = (body->width - 1) * body->dash;
}

int			c_casted(char c, t_total *total, t_body *body)
{
	trunk(&c, total, body);
	return (1);
}

int			no_on_trunk(t_total *total, t_body *body)
{
	int	i;

	c_math(body);
	i = 0;
	while (i < body->left)
	{
		charcat(body->zero ? '0' : ' ', total);
		i++;
	}
	i = 0;
	if (*total->format != 0)
	{
		charcat(*total->format, total);
		total->format++;
	}
	while (i < body->right)
	{
		charcat(' ', total);
		i++;
	}
	return (1);
}

int			c_on_trunk(t_total *total, t_body *body)
{
	char c;

	if (body->l)
		return (wc_on_trunk(total, body));
	else
	{
		c = va_arg(*total->ap, int);
		c_math(body);
		return (c_casted(c, total, body));
	}
	return (1);
}
