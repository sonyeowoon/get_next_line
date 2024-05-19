/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:06:12 by sangseo           #+#    #+#             */
/*   Updated: 2024/05/20 03:22:46 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check_n(const char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return ((char *)s);
		s++;
	}
	if (*s == 0)
		return ((char *)s);
	return (0);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	char		*concat;
	static char	*newline;
	size_t		read_l;
	char		*temp;

	if (newline && *newline)
	{
		if (newline[0] == '\n')
		{
			newline++;
			return ("\n");
		}
		if (*(check_n(newline)))
		{
			free(concat);
			concat = ft_strdup(newline);
			*(check_n(concat) + 1) = 0;
			newline = ft_strdup(check_n(newline) + 1);
			return (concat);
		}
		else
			concat = ft_strdup(newline);
	}
	else
		concat = "";
	read_l = read(fd, buf, BUFFER_SIZE);
	while (read_l > 0)
	{
		buf[read_l] = 0;
		concat = ft_strjoin(concat, buf);
		temp = check_n(concat);
		if (*temp)
		{
			*(temp + 1) = 0;
			newline = ft_strdup(check_n(buf) + 1);
			return (concat);
		}
		read_l = read(fd, buf, BUFFER_SIZE);
	}
	return (NULL);
}
