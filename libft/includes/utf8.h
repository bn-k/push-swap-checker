/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utf8.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 18:15:41 by abbenham          #+#    #+#             */
/*   Updated: 2018/03/08 18:16:01 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTF8_H
# define UTF8_H
# include <wchar.h>
# include "libft.h"
# define M_10XXXXXX 0x80
# define M_110XXXXX 0xc0
# define M_1110XXXX 0xe0
# define M_11110XXX 0xf0
# define SIX_BYTE 0x3f

size_t	ft_putchar_utf8(wchar_t wc);
size_t	ft_putstr_utf8(wchar_t *ws);
size_t	ft_strlen_utf8(wchar_t *ws);
size_t	ft_charlen_utf8(wchar_t wc);
size_t	conv_utf8(char *s, wchar_t wc, int limit);
int		invalide_utf8(wchar_t wc);

#endif
