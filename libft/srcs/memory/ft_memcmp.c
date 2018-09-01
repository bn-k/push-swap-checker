/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:31:04 by abbenham          #+#    #+#             */
/*   Updated: 2017/11/13 11:53:21 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	unsigned char	*s11;
	unsigned char	*s12;

	s11 = (unsigned char*)s1;
	s12 = (unsigned char*)s2;
	i = 0;
	while (n--)
	{
		if (s11[i] != s12[i])
			return (s11[i] - s12[i]);
		i++;
	}
	return (0);
}
