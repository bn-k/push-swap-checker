/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_utf8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:29:14 by abbenham          #+#    #+#             */
/*   Updated: 2018/03/08 17:29:33 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utf8.h"

size_t	ft_strlen_utf8(wchar_t *s)
{
	size_t size;

	size = 0;
	while (*s)
	{
		size += ft_charlen_utf8(*s);
		s++;
	}
	return (size);
}

size_t	ft_charlen_utf8(wchar_t wc)
{
	if (wc < 0x80)
		return (1);
	if (wc <= 0x7ff)
		return (2);
	if (wc <= 0xffff)
		return (3);
	if (wc <= 0x1fffff)
		return (4);
	return (0);
}

int		invalide_utf8(wchar_t wc)
{
	if (wc >= 0x10ffff || wc > WINT_MAX || wc < 0 ||\
			(wc >= 0xd800 && wc <= 0xdfff) ||\
			MB_CUR_MAX == 1)
		return (0);
	return (1);
}
