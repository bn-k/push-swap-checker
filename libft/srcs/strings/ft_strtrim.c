/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:20:20 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/12 18:13:28 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strxlen(char const *s)
{
	int		i;

	i = 0;
	while (s[i] && (i == 0) && (s[i] != ' ' || s[i] != '\t' || s[i] != '\n'))
		i++;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (NULL);
	if (s)
	{
		if (0 == (str = (char *)malloc(sizeof(char) * ft_strxlen(s) + 1)))
			return (NULL);
		while ((i == 0) && (s[j] == ' ' || s[j] == '\t' || s[j] == '\n'))
			j++;
		while (s[j])
			str[i++] = s[j++];
		str[i] = '\0';
		i--;
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			str[i--] = '\0';
	}
	return (str);
}
