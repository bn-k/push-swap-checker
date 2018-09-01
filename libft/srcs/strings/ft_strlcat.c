/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 08:46:48 by abbenham          #+#    #+#             */
/*   Updated: 2017/11/15 12:34:59 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t	d;
	size_t	len_dest;
	size_t	len_src;
	size_t	i;

	i = 0;
	d = 0;
	len_src = 0;
	len_dest = ft_strnlen((char *)dst, size);
	while (dst[d])
		d++;
	while (src[len_src])
		len_src++;
	if (size == 0)
		return (len_dest + len_src);
	while (src[i] && size - 1 > i + len_dest)
	{
		dst[d] = src[i];
		i++;
		d++;
	}
	dst[d] = '\0';
	return (len_dest + len_src);
}
