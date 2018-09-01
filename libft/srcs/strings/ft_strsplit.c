/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 16:28:08 by abbenham          #+#    #+#             */
/*   Updated: 2018/08/17 14:52:32 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static void		ft_test(char const *s, char c, int *p)
{
	while (s[*p] == c)
		*p = *p + 1;
}

static int		wdlen(char const *s, char c, int *b)
{
	int			a;
	int			d;

	a = 0;
	d = 0;
	while (s[a] == c)
		a++;
	while (s[a])
	{
		while (s[a] && s[a] != c)
		{
			a++;
			*b = *b + 1;
		}
		while (s[a] == c)
			a++;
		d++;
	}
	return (d);
}

char			**ft_strsplit(char const *s, char c)
{
	int			a;
	int			d;
	int			b;
	int			p;
	char		**tab;

	a = 0;
	b = 0;
	p = 0;
	if (s == 0 || !(tab = (char **)malloc(sizeof(tab) * (wdlen(s, c, &b) + 1))))
		return (0);
	ft_test(s, c, &p);
	while (s[p])
	{
		d = 0;
		tab[a] = (char *)malloc(sizeof(*tab) * b + 1);
		while (s[p] && s[p] != c)
			tab[a][d++] = s[p++];
		ft_test(s, c, &p);
		tab[a++][d] = 0;
	}
	tab[a] = 0;
	return (tab);
}
