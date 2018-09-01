/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_variation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 13:07:29 by abbenham          #+#    #+#             */
/*   Updated: 2018/03/08 16:56:19 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ws_math(wchar_t *ws, t_body *body)
{
	body->len = ft_strlen_utf8(ws);
	if (body->point && body->len > body->precis)
		body->len = body->precis;
	body->left = (body->width - body->len) * (body->dash ? 0 : 1);
	body->right = (body->width - body->len) * body->dash;
}

static int	ws_casted(wchar_t *ws, t_total *total, t_body *body)
{
	int	i;

	i = 0;
	ws_math(ws, body);
	trunk_unicode_left_distance(total, body);
	trunk_unicode_ws(ws, total, body);
	trunk_unicode_right_distance(total, body);
	return (1);
}

int			ws_on_trunk(t_total *total, t_body *body)
{
	wchar_t *ws;

	if (!(ws = va_arg(*total->ap, wchar_t *)))
		return (ws_casted(L"(null)", total, body));
	else
		return (ws_casted(ws, total, body));
}
