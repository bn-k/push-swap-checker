/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:15:13 by abbenham          #+#    #+#             */
/*   Updated: 2017/11/19 04:58:29 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*save;

	if (c == 0)
		return ((char *)s + ft_strlen(s));
	if (*s == '\0')
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			save = (char *)s;
		s++;
	}
	return (save);
}
