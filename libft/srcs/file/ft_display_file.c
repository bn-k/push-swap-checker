/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:06:11 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/12 18:11:42 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int		ft_display_file(char *str, int to_close)
{
	char	buf[7];
	int		fd;
	int		size;

	fd = 0;
	fd = open(str, O_RDWR);
	while ((size = read(fd, buf, 7)))
		write(1, buf, size);
	if (to_close > 0)
		close(fd);
	return (fd);
}
