/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:49:03 by abbenham          #+#    #+#             */
/*   Updated: 2017/11/15 14:19:00 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	int				i;
	void			*s;
	unsigned char	*sc;

	i = 0;
	if (0 == (s = (void *)malloc(sizeof(void) * size)))
		return (NULL);
	sc = s;
	while (size--)
		sc[i++] = 0;
	return (s);
}
