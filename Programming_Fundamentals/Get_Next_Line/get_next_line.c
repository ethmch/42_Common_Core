/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emechali <emechali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 15:46:11 by emechali          #+#    #+#             */
/*   Updated: 2026/11/24 17:39:30 by emechali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line;
	char		*final_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (line == NULL)
	{
		line = malloc(sizeof(char) * 1);
		if (line == NULL)
			return (NULL);
		line[0] = '\0';
	}
	line = ft_read(fd, line);
	if (line == NULL)
		return (NULL);
	if (line[0] == '\0')
		return (free(line), line = NULL, NULL);
	final_line = ft_line_stop(line);
	if (final_line == NULL)
		return (free(line), line = NULL, NULL);
	line = ft_rest(line, final_line);
	return (final_line);
}
/*
#include <stdio.h>
#include <fcntl.h>
int	main()
{
	int		fd;
	char	*line;

	printf("BUFFER_SIZE : %ld\n", (long)BUFFER_SIZE);
	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
*/
