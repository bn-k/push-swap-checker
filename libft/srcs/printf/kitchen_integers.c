/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kitchen_integers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:02:54 by abbenham          #+#    #+#             */
/*   Updated: 2018/03/09 17:16:14 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	trunk_integers_left_distance(t_total *total, t_body *body)
{
	int		i;

	i = 0;
	while ((!body->zero || body->point) && i < body->left)
	{
		charcat(' ', total);
		i++;
	}
	if (body->minus)
		charcat('-', total);
	else if (body->plus)
		charcat('+', total);
	else if (body->space)
		charcat(' ', total);
}

void	trunk_integers_left_zero(t_total *total, t_body *body)
{
	int	i;

	i = 0;
	while (!body->dash && !body->point && body->zero && i < body->left)
	{
		charcat('0', total);
		i++;
	}
	while (i < body->fill)
	{
		charcat('0', total);
		i++;
	}
}

void	trunk_integers_value(char *s, t_total *total, t_body *body)
{
	int	i;

	i = 0;
	if (!(!body->precis && body->point && *s == '0'))
	{
		while (i < body->len)
		{
			charcat(s[i], total);
			i++;
		}
	}
}

void	trunk_integers_right_distance(t_total *total, t_body *body)
{
	int		i;

	i = 0;
	while (i < body->right)
	{
		charcat(' ', total);
		i++;
	}
}

void	trunk_integers(char *s, t_total *total, t_body *body)
{
	trunk_integers_left_distance(total, body);
	trunk_integers_left_zero(total, body);
	trunk_integers_value(s, total, body);
	trunk_integers_right_distance(total, body);
}
