/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:51:13 by abbenham          #+#    #+#             */
/*   Updated: 2018/08/21 18:19:22 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		**tabcat(char **tab, char *ptr, int new_size)
{
	char	**new;
	int		i;

	i = 0;
	new = (char**)malloc(sizeof(char*) * (new_size + 2));
	if (tab)
		while (i < new_size - 1)
		{
			new[i] = tab[i];
			i++;
		}
	new[i] = ptr;
	new[i + 1] = NULL;
	return (new);
}
