/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:35:54 by abbenham          #+#    #+#             */
/*   Updated: 2018/03/08 17:37:04 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_print_adress(long unsigned int nbr)
{
	int				i;
	int				nbr_tab[13];
	char			base[17];
	int				len;

	ft_strcpy(base, "0123456789abcdef");
	len = ft_putstr("0x");
	i = 0;
	if (nbr == 0)
		len += ft_putchar(base[0]);
	while (nbr > 0)
	{
		nbr_tab[i++] = nbr % 16;
		nbr = nbr / 16;
	}
	while (i > 0)
		len += ft_putchar(base[nbr_tab[i-- - 1]]);
	return (len);
}
