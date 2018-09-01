/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utf8_to_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:26:05 by abbenham          #+#    #+#             */
/*   Updated: 2018/03/08 17:28:53 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utf8.h"

static size_t	two_byte_utf8(char *s, wchar_t wc)
{
	s[0] = (wc >> 6) | M_110XXXXX;
	s[1] = (wc & SIX_BYTE) + M_10XXXXXX;
	return (2);
}

static size_t	three_byte_utf8(char *s, wchar_t wc)
{
	s[0] = (wc >> 12) | M_1110XXXX;
	s[1] = ((wc >> 6) & SIX_BYTE) | M_10XXXXXX;
	s[2] = (wc & SIX_BYTE) + M_10XXXXXX;
	return (3);
}

static size_t	four_byte_utf8(char *s, wchar_t wc)
{
	s[0] = (wc >> 18) | M_11110XXX;
	s[1] = ((wc >> 12) & SIX_BYTE) | M_10XXXXXX;
	s[2] = ((wc >> 6) & SIX_BYTE) | M_10XXXXXX;
	s[3] = (wc & SIX_BYTE) + M_10XXXXXX;
	return (4);
}

size_t			conv_utf8(char *s, wchar_t wc, int limit)
{
	if (wc < 0x80 && limit > 0)
	{
		s[0] = wc;
		return (1);
	}
	if (wc <= 0x7ff && limit > 1)
		return (two_byte_utf8(s, wc));
	if (wc <= 0xffff && limit > 2)
		return (three_byte_utf8(s, wc));
	if (wc <= 0x1fffff && limit > 3)
		return (four_byte_utf8(s, wc));
	return (0);
}
