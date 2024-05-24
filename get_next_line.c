/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 04:06:14 by sangseo           #+#    #+#             */
/*   Updated: 2024/05/25 01:13:30 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*chk_nl(char **buf)
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

static char	*ft_allocfree(char *s1, char *s2, int n)
{
	char	*tmp;

	tmp = s1;
	if (n == 0)
		s1 = ft_strdup(s1);
	else
		s1 = ft_strjoin(s1, s2);
	free(tmp);
	return (s1);
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
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == 0)
		return (0);
	read_l = read(fd, buf, BUFFER_SIZE);
	if (read_l < 0)
	{
		free(buf);
		return (0);
	}
	if (read_l == 0)
	{
		free(buf);
		return (tmp);
	}
	buf[read_l] = 0;
	save = chk_nl(&buf);
	if (save)
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
	if (!tmp)
		tmp = ft_strdup(buf);
	else if (tmp)
		tmp = ft_allocfree(tmp, buf, 1);
	while (read_l > 0)
	{
		read_l = read(fd, buf, BUFFER_SIZE);
		buf[read_l] = 0;
		save = chk_nl(&buf);
		tmp = ft_allocfree(tmp, buf, 1);
		if (save)
			break ;
	}
	free(buf);
	return (tmp);
}
