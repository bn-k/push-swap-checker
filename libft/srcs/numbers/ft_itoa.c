/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 21:21:25 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/13 11:56:26 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char	*s;
	int		nblen;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	sign = n < 0 ? -1 : 1;
	nblen = ft_nbrlen(n);
	n = n < 0 ? -n : n;
	if (!(s = (char *)malloc(sizeof(char) * nblen + 1)))
		return (NULL);
	s[nblen] = 0;
	while (--nblen >= 0)
	{
		s[nblen] = n % 10 + 48;
		n /= 10;
	}
	s[0] = sign < 0 ? '-' : s[0];
	return (s);
}

char			*ft_itoa_iull(unsigned long long n)
{
	char	*s;
	int		nblen;

	if (n == 0)
		return (ft_strdup("0"));
	nblen = ft_nbrlen_iull(n);
	if (!(s = (char *)malloc(sizeof(char) * nblen + 1)))
		return (NULL);
	s[nblen] = 0;
	while (--nblen >= 0)
	{
		s[nblen] = n % 10 + 48;
		n /= 10;
	}
	return (s);
}
