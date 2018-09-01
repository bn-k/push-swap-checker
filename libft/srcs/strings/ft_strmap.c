/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:51:37 by abbenham          #+#    #+#             */
/*   Updated: 2017/11/19 04:03:20 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	str = (NULL);
	if (s)
	{
		i = 0;
		if (0 == (str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
			return (NULL);
		while (*s)
			str[i++] = f(*s++);
		str[i] = 0;
	}
	return (str);
}
