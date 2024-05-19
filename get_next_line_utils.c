/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:48:44 by sangseo           #+#    #+#             */
/*   Updated: 2024/05/19 18:48:39 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*arr;
	int		i;

	arr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!arr)
		return (0);
	i = 0;
	while (s[i])
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = 0;
	return (arr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;
	size_t	i;
	size_t	j;

	i = ft_strlen((const char *)s1) + ft_strlen((const char *)s2);
	arr = (char *)malloc(sizeof(char) * (i + 1));
	if (!arr)
		return (0);
	i = 0;
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		arr[i++] = s2[j++];
	}
	arr[i] = 0;
	return (arr);
}
