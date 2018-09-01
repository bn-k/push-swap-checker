/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 13:02:06 by abbenham          #+#    #+#             */
/*   Updated: 2018/08/21 19:27:19 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	charcat(char c, t_total *total)
{
	if (total->i == BID)
	{
		write(1, g_trunk, total->i);
		total->i = 0;
	}
	g_trunk[total->i] = c;
	total->i++;
	total->quanta++;
}

void	init_total(t_total *total, const char *format, va_list *ap)
{
	total->quanta = 0;
	ft_bzero((void*)g_trunk, BID);
	total->i = 0;
	total->format = format;
	total->ap = ap;
}

void	body_parser(t_total *total, t_body *body)
{
	ft_bzero(body, sizeof(t_body));
	while (isflag(*total->format) || is_modifier(*total->format) ||\
			*total->format == '.' || ft_isdigit(*total->format))
	{
		flags(total, body);
		width_and_precision(total, body);
		modifier(total, body);
	}
}
