/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 22:02:22 by abbenham          #+#    #+#             */
/*   Updated: 2018/02/14 12:05:19 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putstr(char const *s)
{
	size_t len;

	len = 0;
	if (s)
		while (*s)
		{
			ft_putchar(*s);
			len++;
			s++;
		}
	return (len);
}
