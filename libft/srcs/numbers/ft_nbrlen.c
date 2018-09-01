/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 17:07:47 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/13 11:56:30 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlen(int long long nb)
{
	if (nb < 10 && nb >= 0)
		return (1);
	if (nb < 0)
		return (1 + ft_nbrlen(nb * -1));
	if (nb > 9)
		return (1 + ft_nbrlen(nb / 10));
	return (0);
}

size_t	ft_nbrlen_iull(unsigned long long nb)
{
	if (nb < 10)
		return (1);
	if (nb > 9)
		return (1 + ft_nbrlen_iull(nb / 10));
	return (0);
}

size_t	ft_nbrlen_base(unsigned long long nb, unsigned int lenbase)
{
	if (nb < lenbase)
		return (1);
	if (nb > lenbase - 1)
		return (1 + ft_nbrlen_base((nb / lenbase), lenbase));
	return (0);
}
