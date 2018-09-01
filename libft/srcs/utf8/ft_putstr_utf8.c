/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_utf8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:29:51 by abbenham          #+#    #+#             */
/*   Updated: 2018/03/08 17:29:54 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utf8.h"

size_t	ft_putstr_utf8(wchar_t *ws)
{
	size_t len;

	len = 0;
	if (ws)
		while (*ws)
		{
			len += ft_putchar_utf8(*ws);
			ws++;
		}
	return (len);
}
