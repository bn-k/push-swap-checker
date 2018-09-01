/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:40:48 by abbenham          #+#    #+#             */
/*   Updated: 2017/11/19 03:31:15 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
		if ((*s1++ != *s2++) || *s1 == 0 || *s2 == 0)
			return (*(unsigned char*)(s1 - 1) - *(unsigned char*)(s2 - 1));
	return (0);
}
