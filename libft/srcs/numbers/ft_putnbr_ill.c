/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 22:10:59 by abbenham          #+#    #+#             */
/*   Updated: 2018/03/08 17:32:28 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_ill(int long long nb)
{
	if (nb < -9223372036854775807)
		ft_putstr("-9223372036854775808");
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
		}
		if (nb >= 10)
		{
			ft_putnbr_ill(nb / 10);
			ft_putnbr_ill(nb % 10);
		}
		else
			ft_putchar(nb + 48);
	}
}

void	ft_putnbr_iull(int unsigned long long n)
{
	if (n > 9)
	{
		ft_putnbr_iull(n / 10);
		ft_putnbr_iull(n % 10);
	}
	else
		ft_putchar(n + 48);
}
