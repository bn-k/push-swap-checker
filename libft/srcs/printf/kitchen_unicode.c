/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kitchen_unicode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:05:43 by abbenham          #+#    #+#             */
/*   Updated: 2018/03/09 17:53:57 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	trunk_unicode_left_distance(t_total *total, t_body *body)
{
	int		i;

	i = 0;
	while (i < body->left)
	{
		charcat(body->zero ? '0' : ' ', total);
		i++;
	}
}

void	trunk_unicode_ws(wchar_t *ws, t_total *total, t_body *body)
{
	int		s_i;
	int		ws_i;
	char	s[body->len];

	ws_i = 0;
	s_i = 0;
	while (s_i < body->len)
	{
		s_i += conv_utf8(&s[s_i], ws[ws_i], MB_CUR_MAX);
		ws_i++;
	}
	s_i = 0;
	while (s_i < body->len)
	{
		charcat(s[s_i], total);
		s_i++;
	}
}

void	trunk_unicode_wc(wchar_t *ws, t_total *total, t_body *body)
{
	int		s_i;
	int		ws_i;
	char	s[body->len];

	ws_i = 0;
	s_i = 0;
	while (s_i < body->len)
	{
		s_i += conv_utf8(&s[s_i], ws[ws_i], 4);
		ws_i++;
	}
	s_i = 0;
	while (s_i < body->len)
	{
		charcat(s[s_i], total);
		s_i++;
	}
}

void	trunk_unicode_right_distance(t_total *total, t_body *body)
{
	int		i;

	i = 0;
	while (i < body->right)
	{
		charcat(' ', total);
		i++;
	}
}
