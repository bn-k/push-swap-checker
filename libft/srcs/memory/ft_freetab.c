/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:54:34 by abbenham          #+#    #+#             */
/*   Updated: 2018/08/21 16:15:18 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tablen(void **tab)
{
	int		i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			i++;
	}
	return (i);
}

void	ft_freetab(void **tab, int size)
{
	int		i;

	ft_printf("freetab size = %d\n", size);
	if (tab)
	{
		i = 0;
		while (i < size)
		{
			ft_printf("tab[%d] = %p\n", i, &tab[i]);
			free(tab[i]);
			i++;
		}
		ft_printf("tab = %p\n", tab);
		free(tab);
		tab = NULL;
	}
	ft_printf("================\n");
}
