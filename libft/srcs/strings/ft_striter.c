/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:44:36 by abbenham          #+#    #+#             */
/*   Updated: 2017/11/19 03:59:16 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Applique la fonction f à chaque caractère de la chaine de
**caractères passée en paramètre. Chaque caractère est passé
**par adresse à la fonction f afin de pouvoir être modifié si
**nécéssaire.
*/

void	ft_striter(char *s, void (*f)(char *))
{
	if (s)
	{
		while (*s)
			f(s++);
	}
}
