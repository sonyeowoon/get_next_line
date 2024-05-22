/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 04:06:14 by sangseo           #+#    #+#             */
/*   Updated: 2024/05/23 01:43:51 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*chk_nl(char **buf)
{
	int	i;
	char	*s;

	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			s = ft_strdup((*buf) + i + 1);
			(*buf)[i + 1] = 0;
			return (s);
		}
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*tmp;
	ssize_t		read_l;
	static char	*save;

	tmp = 0;
	if (save && *save)
	{
		buf = save;
		save = chk_nl(&save);
		if (!save)
		{
			tmp = ft_strdup(buf);
			free(buf);
		}
		else
			return (buf);
	}
	else if (save && *save == 0)
	{
		free(save);
		save = 0;
	}
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == 0)
		return (0);
	read_l = read(fd, buf, BUFFER_SIZE);
	if (read_l <= 0)
	{
		free(buf);
		return (0);
	}
	buf[read_l] = 0;
	save = chk_nl(&buf);
	if (save)
		return (buf);
	if (!tmp)
		tmp = ft_strdup(buf);
	while (read_l > 0)
	{
		read_l = read(fd, buf, BUFFER_SIZE);
		buf[read_l] = 0;
		save = tmp;
		tmp = ft_strjoin(tmp, buf);
		free(save);
		save = 0;
	}
	free(buf);
	return (tmp);
}
