/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 04:06:14 by sangseo           #+#    #+#             */
/*   Updated: 2024/05/25 16:36:01 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*chk_nl(char **buf)
{
	int		i;
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

static ssize_t	chk_read(int fd, char *buf, char **tmp)
{
	ssize_t	read_l;

	read_l = read(fd, buf, BUFFER_SIZE);
	if (read_l < 0)
	{
		free(buf);
		if (*tmp)
			free(*tmp);
		*tmp = 0;
	}
	else if (read_l == 0)
		free(buf);
	return (read_l);
}

static char	*nl_return(char *tmp, char *buf)
{
	if (tmp)
	{
		tmp = ft_allocfree(tmp, buf, 1);
		free(buf);
		return (tmp);
	}
	else
		return (buf);
}

static char	*get_line(int fd, char **save, char *tmp)
{
	ssize_t	read_l;
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == 0)
		return (0);
	read_l = 1;
	while (read_l > 0)
	{
		read_l = chk_read(fd, buf, &tmp);
		if (read_l <= 0)
			return (tmp);
		buf[read_l] = 0;
		*save = chk_nl(&buf);
		if (*save)
			return (nl_return(tmp, buf));
		if (!tmp)
			tmp = ft_strdup(buf);
		else if (tmp)
			tmp = ft_allocfree(tmp, buf, 1);
	}
	free(buf);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*tmp;
	static char	*save;

	tmp = 0;
	if (save && *save)
	{
		buf = save;
		save = chk_nl(&save);
		if (!save)
		{
			tmp = ft_allocfree(buf, 0, 0);
		}
		else
			return (buf);
	}
	else if (save && *save == 0)
	{
		free(save);
		save = 0;
	}
	tmp = get_line(fd, &save, tmp);
	return (tmp);
}
