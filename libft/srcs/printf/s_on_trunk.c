/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_variation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 13:07:29 by abbenham          #+#    #+#             */
/*   Updated: 2018/03/08 16:37:37 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		s_math(char *s, t_body *body)
{
	body->len = ft_strlen(s);
	if (body->point && body->len > body->precis)
		body->len = body->precis;
	body->left = (body->width - body->len) * (body->dash ? 0 : 1);
	body->right = (body->width - body->len) * body->dash;
}

int				s_casted(char *s, t_total *total, t_body *body)
{
	s_math(s, body);
	trunk(s, total, body);
	return (1);
}

int				s_on_trunk(t_total *total, t_body *body)
{
	char *s;

	if (body->l)
		return (ws_on_trunk(total, body));
	else if (!(s = va_arg(*total->ap, char *)))
		return (s_casted("(null)", total, body));
	else
		return (s_casted(s, total, body));
}
