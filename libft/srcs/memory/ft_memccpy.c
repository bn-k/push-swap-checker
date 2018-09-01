/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:36:35 by abbenham          #+#    #+#             */
/*   Updated: 2017/11/13 15:46:12 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*str_src;
	unsigned char	*str_dst;

	str_src = (unsigned char *)src;
	str_dst = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		str_dst[i] = str_src[i];
		if (str_src[i] == (unsigned char)c)
		{
			i++;
			return (dst + i);
		}
		i++;
	}
	return (NULL);
}
