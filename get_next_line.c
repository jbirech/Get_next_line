/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobirech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 19:10:53 by jobirech          #+#    #+#             */
/*   Updated: 2018/06/22 19:54:52 by jobirech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		add_null(int fd, char **buff, char **line)
{
	char	*nl;
	char	*heap;

	nl = ft_strchr(buff[fd], '\n');
	if (nl)
	{
		heap = buff[fd];
		*nl = '\0';
		*line = ft_strdup(buff[fd]);
		buff[fd] = ft_strdup(nl + 1);
		free(heap);
		return (1);
	}
	else if (*buff[fd])
	{
		*line = ft_strdup(buff[fd]);
		buff[fd] = ft_strnew(BUFF_SIZE + 1);
		return (1);
	}
	return (0);
}

int		check_nl(int fd, char **buff)
{
	char	*tmp;
	char	*leak;
	int		i;

	tmp = ft_strnew(BUFF_SIZE + 1);
	while ((i = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		leak = buff[fd];
		buff[fd] = ft_strjoin(buff[fd], tmp);
		ft_strdel(&leak);
		ft_bzero(tmp, BUFF_SIZE);
	}
	free(tmp);
	return (i ? 1 : 0);
}

int		get_next_line(const int fd, char **line)
{
	static char		*buff[4864];

	if ((BUFF_SIZE < 1 || fd < 0 || !line ||
		check_nl(fd, &buff[fd])))
		return (-1);
	if (add_null(fd, &buff[fd], line))
		return (1);
	return (0);
}
