/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnuminfo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:31:47 by abbenham          #+#    #+#             */
/*   Updated: 2018/03/08 17:31:51 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnuminfo(int nb, char *spec)
{
	ft_putendl(spec);
	ft_putnbr(nb);
	ft_putchar('\n');
}
