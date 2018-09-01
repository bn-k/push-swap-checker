/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:30:50 by abbenham          #+#    #+#             */
/*   Updated: 2017/11/15 13:18:31 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	size_t	needlen;

	i = 0;
	if (!(len))
		return (NULL);
	if (0 == (needlen = ft_strnlen(needle, len)))
		return (char *)haystack;
	while (i <= (int)(len - needlen))
	{
		if ((haystack[0] == needle[0]) &&
				(0 == ft_strncmp(haystack, needle, needlen)))
			return (char *)haystack;
		haystack++;
		i++;
	}
	return (NULL);
}
