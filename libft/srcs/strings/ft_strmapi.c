/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:30:47 by abbenham          #+#    #+#             */
/*   Updated: 2017/11/19 04:03:57 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		{
			str[i] = f(i, *s++);
			i++;
		}
		str[i] = 0;
	}
	return (str);
}
