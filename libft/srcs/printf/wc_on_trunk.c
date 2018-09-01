/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_variation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 13:07:29 by abbenham          #+#    #+#             */
/*   Updated: 2018/03/08 16:57:09 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "utf8.h"

int		wc_casted(wchar_t wc, t_total *total, t_body *body)
{
	int		i;
	char	*s;

	i = 0;
	if (MB_CUR_MAX == 1 && wc <= 255)
		return (s_casted((char *)&wc, total, body));
	else if (!invalide_utf8(wc))
		return (-1);
	s = (char *)malloc(sizeof(char) * 5);
	body->len = ft_charlen_utf8(wc);
	body->left = (body->width - body->len) * (body->dash ? 0 : 1);
	body->right = (body->width - body->len) * body->dash;
	trunk_unicode_left_distance(total, body);
	trunk_unicode_wc(&wc, total, body);
	trunk_unicode_right_distance(total, body);
	free(s);
	return (1);
}

int		wc_on_trunk(t_total *total, t_body *body)
{
	wchar_t wc;

	wc = va_arg(*total->ap, wint_t);
	return (wc_casted(wc, total, body));
}
