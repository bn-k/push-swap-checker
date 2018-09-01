/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 12:00:10 by abbenham          #+#    #+#             */
/*   Updated: 2018/08/22 13:16:25 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strxdup(const char *s1)
{
	char	*dup;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1[0] == '\n' && s1[1] == '\n')
		return (ft_strdup(""));
	if (!(dup = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	while (s1[i] && s1[i] != '\n')
		dup[j++] = s1[i++];
	dup[j] = '\0';
	return (dup);
}

int			end_of_line(char **line, t_x *x)
{
	char	*next;
	char	*tmp;

	tmp = NULL;
	if ((next = ft_strchr(x->s, '\n')))
	{
		if (!(*line = ft_strxdup(x->s)))
			return (-1);
		tmp = x->s;
		if (!(x->s = ft_strdup(next + 1)))
			return (-1);
		ft_bzero(tmp, ft_strlen(tmp));
		ft_memdel((void **)&tmp);
	}
	else
	{
		if (!(*line = ft_strdup(x->s)))
			return (-1);
		ft_bzero(x->s, ft_strlen(tmp));
		ft_memdel((void **)&x->s);
	}
	return (1);
}

int			reader(const int fd, t_x *x)
{
	char	*tmp;

	while (x->size && !(ft_strchr(x->s, '\n')))
	{
		if ((x->size = read(fd, x->buf, BUFF_SIZE)))
		{
			if (x->size < 0)
				return (-1);
			x->buf[BUFF_SIZE] = '\0';
			tmp = x->s;
			if (!(x->s = ft_strjoin(tmp, x->buf)))
				return (-1);
			ft_bzero(x->buf, BUFF_SIZE);
			ft_memdel((void **)&tmp);
		}
	}
	if (x->size > 0)
		return (1);
	return (0);
}

t_x			*ft_init(int fd)
{
	t_x		*list;

	if (!(list = (t_x *)malloc(sizeof(t_x))))
		return (NULL);
	if (!(list->buf = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (NULL);
	if (!(list->s = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (NULL);
	list->size = 1;
	list->fd = fd;
	list->next = NULL;
	ft_bzero(list->buf, BUFF_SIZE + 1);
	ft_bzero(list->s, BUFF_SIZE + 1);
	return (list);
}

int			get_next_line(const int fd, char **line)
{
	static t_x	*list;
	t_x			*x;

	if (!(list = list ? list : ft_init(fd)))
		return (-1);
	x = list;
	while (x->fd != fd)
	{
		if (!x->next)
			if (!(x->next = ft_init(fd)))
				return (-1);
		x = x->next;
	}
	if (fd < 0 || !line || BUFF_SIZE <= 0 ||\
			read(fd, x->buf, 0) == -1 || fd == 1)
		return (-1);
	if (!(reader(fd, x)))
		return (-1);
	if (x->s)
		if (*x->s)
			return (end_of_line(line, x));
	return (0);
}
