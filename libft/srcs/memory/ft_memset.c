/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:06:34 by abbenham          #+#    #+#             */
/*   Updated: 2017/11/13 15:33:59 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*oct;

	i = 0;
	oct = b;
	while (i < len)
	{
		*oct = (unsigned char)c;
		oct++;
		i++;
	}
	return (b);
}
