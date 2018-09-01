/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_variation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 13:07:29 by abbenham          #+#    #+#             */
/*   Updated: 2018/03/08 17:16:10 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	d_math(long long *nb, t_body *body)
{
	if (*nb < 0)
	{
		body->minus = 1;
		*nb = -*nb;
	}
	body->len = ft_nbrlen_iull(*nb);
	if (body->point && body->precis == 0 && *nb == 0)
		body->len = 0;
	if (body->point)
	{
		body->fill = POS(body->precis - body->len);
	}
	body->plus = body->plus * !body->minus;
	body->left = POS(body->width - body->len - SIGN - body->fill)\
				* (body->dash ? 0 : 1);
	body->right = (body->width - body->len - SIGN - body->fill)\
				* body->dash;
}

static int	cast(long long nb, t_total *total, t_body *body)
{
	char *s;

	d_math(&nb, body);
	s = ft_itoa_iull(nb);
	trunk_integers(s, total, body);
	free(s);
	return (1);
}

int			d_on_trunk(t_total *tt, t_body *bd)
{
	if (tt->format[-1] == 'D')
		return (cast((long long)va_arg(*tt->ap, long long), tt, bd));
	else if (bd->z == 1)
		return (cast((size_t)va_arg(*tt->ap, size_t), tt, bd));
	else if (bd->j == 1)
		return (cast((intmax_t)va_arg(*tt->ap, long long), tt, bd));
	else if (bd->l == 1)
		return (cast((long long)va_arg(*tt->ap, long), tt, bd));
	else if (bd->l == 2)
		return (cast((long long)va_arg(*tt->ap, long long), tt, bd));
	else if (bd->h == 1)
		return (cast((short)va_arg(*tt->ap, int), tt, bd));
	else if (bd->h == 2)
		return (cast((signed char)va_arg(*tt->ap, void*), tt, bd));
	else
		return (cast((long long)va_arg(*tt->ap, int), tt, bd));
}
