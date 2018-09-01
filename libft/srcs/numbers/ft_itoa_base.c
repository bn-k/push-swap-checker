/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 21:21:25 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/13 11:56:28 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrev(char *s)
{
	int		beg;
	int		end;
	char	tmp;

	beg = 0;
	end = ft_strlen(s) - 1;
	while (beg <= end)
	{
		tmp = s[beg];
		s[beg] = s[end];
		s[end] = tmp;
		beg++;
		end--;
	}
	return (s);
}

static int		ft_verif_doublon(char *s1, char *s2, int pos)
{
	int				i;

	i = 0;
	while (s1[i + pos])
	{
		if (s1[i + pos] == s2[i])
			return (1);
		i++;
	}
	if (s1[pos] != '\0')
		return (ft_verif_doublon(s1, s2, pos + 1));
	return (0);
}

static int		ft_len_base(char *base)
{
	int				i;

	i = 0;
	if (ft_verif_doublon(base, base, 1) == 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

char			*ft_itoa_base(unsigned long long n, char *base)
{
	char	*s;
	int		div;
	int		i;

	if (n == 0)
		return (ft_strdup("0"));
	s = (char *)malloc(sizeof(char) * 33);
	i = 0;
	div = ft_len_base(base);
	while (n > 0)
	{
		s[i] = base[n % div];
		n = n / div;
		i++;
	}
	s[i] = 0;
	return (ft_strrev(s));
}
