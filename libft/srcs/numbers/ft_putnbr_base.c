/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 17:58:47 by abbenham          #+#    #+#             */
/*   Updated: 2018/03/08 17:31:15 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_verif_doublon(char *s1, char *s2, int pos)
{
	int				i;

	i = 0;
	while (s1[i + pos])
	{
		if (s1[i + pos] == s2[i])
			return (1);
		i++;
	}
	if (s1[pos] != '\0')
		return (ft_verif_doublon(s1, s2, pos + 1));
	return (0);
}

int					ft_len_base(char *base)
{
	int				i;

	i = 0;
	if (ft_verif_doublon(base, base, 1) == 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

size_t				ft_putnbr_base(unsigned long long nb, char *base)
{
	int				i;
	int				nb_tab[33];
	int				len_base;
	size_t			len;

	len = 0;
	len_base = ft_len_base(base);
	i = 0;
	if (nb == 0 && len_base != 0)
		len += ft_putchar(base[0]);
	while (nb > 0 && len_base != 0)
	{
		nb_tab[i++] = nb % len_base;
		nb = nb / len_base;
	}
	while (i > 0 && len_base != 0)
		len += ft_putchar(base[nb_tab[i-- - 1]]);
	return (len);
}
