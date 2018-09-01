/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_variation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 13:07:29 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/13 11:52:44 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		o_math(long long *nb, t_body *body)
{
	if ((!body->precis && body->point) && *nb == 0 && !body->sharp)
		body->len = 0;
	else
		body->len = ft_nbrlen_base(*nb, 8);
	if (body->point && nb != 0)
		body->fill = POS(body->precis - body->len);
	body->sharp = body->sharp * ((!body->fill) && *nb != 0);
	body->left = POS(body->width - body->len - body->fill - body->sharp)\
				* (body->dash ? 0 : 1);
	body->right = POS(body->width - body->len - body->fill - body->sharp)\
				* body->dash;
}

static int		cast(long long nb, t_total *total, t_body *body)
{
	char *s;

	o_math(&nb, body);
	s = ft_itoa_base(nb, "01234567");
	trunk_o(s, total, body);
	free(s);
	return (1);
}

int				o_on_trunk(t_total *tt, t_body *bd)
{
	if (tt->format[-1] == 'O')
		return (cast((unsigned long long)va_arg(*tt->ap, long long), tt, bd));
	else if (bd->h == 1)
		return (cast((unsigned short)va_arg(*tt->ap, int), tt, bd));
	else if (bd->z == 1)
		return (cast((size_t)va_arg(*tt->ap, size_t), tt, bd));
	else if (bd->h == 2)
		return (cast((unsigned char)va_arg(*tt->ap, int), tt, bd));
	else if (bd->l == 1)
		return (cast((unsigned long long)va_arg(*tt->ap, long), tt, bd));
	else if (bd->l == 2)
		return (cast((unsigned long long)va_arg(*tt->ap, long long), tt, bd));
	else if (bd->j == 1)
		return (cast((uintmax_t)va_arg(*tt->ap, long long), tt, bd));
	else
		return (cast((unsigned int)va_arg(*tt->ap, unsigned int), tt, bd));
}
