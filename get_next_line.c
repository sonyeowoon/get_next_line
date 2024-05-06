/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:06:12 by sangseo           #+#    #+#             */
/*   Updated: 2024/05/07 08:20:27 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	char	*buf;

}

#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int	fd;

	fd = open("", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	//printf("-----------end--------------");
}
