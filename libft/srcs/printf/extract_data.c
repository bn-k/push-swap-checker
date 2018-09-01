/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:08:44 by abbenham          #+#    #+#             */
/*   Updated: 2018/03/08 17:13:57 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		isflag(int c)
{
	int		i;
	char	flag[7];

	ft_strcpy(flag, "#0- +'");
	i = -1;
	while (++i < 6)
		if (flag[i] == c)
			return (i + 1);
	return (0);
}

void	flags(t_total *total, t_body *body)
{
	int	i;

	i = 0;
	while ((i = isflag(*total->format)))
	{
		body->sharp = (i == 1 ? 1 : body->sharp);
		body->zero = (i == 2 ? 1 : body->zero);
		body->dash = (i == 3 ? 1 : body->dash);
		body->space = (i == 4 ? 1 : body->space);
		body->plus = (i == 5 ? 1 : body->plus);
		body->apos = (i == 6 ? 1 : body->apos);
		total->format++;
	}
}

void	width_and_precision(t_total *total, t_body *body)
{
	if (ft_isdigit(*total->format))
	{
		body->width = ft_atoi(total->format);
		while (ft_isdigit(*total->format))
			total->format++;
	}
	if (*total->format == '.')
	{
		body->point = 1;
		total->format++;
		if (ft_isdigit(*total->format))
		{
			body->precis = ft_atoi(total->format);
			while (ft_isdigit(*total->format))
				total->format++;
		}
		else
			body->precis = 0;
	}
}

int		is_modifier(char c)
{
	int		i;
	char	mod[6];

	ft_strcpy(mod, "hljzq");
	i = -1;
	while (++i < 5)
		if (mod[i] == c)
			return (i + 1);
	return (0);
}

void	modifier(t_total *total, t_body *body)
{
	int	i;

	i = 0;
	while ((i = is_modifier(*total->format)))
	{
		body->h = (i == 1 ? 1 + body->h : body->h);
		body->l = (i == 2 ? 1 + body->l : body->l);
		body->j = (i == 3 ? 1 : body->j);
		body->z = (i == 4 ? 1 : body->z);
		body->q = (i == 5 ? 1 : body->q);
		total->format++;
	}
}
