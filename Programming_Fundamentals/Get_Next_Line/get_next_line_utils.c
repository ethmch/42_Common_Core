/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emechali <emechali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 15:50:38 by emechali          #+#    #+#             */
/*   Updated: 2026/11/24 18:10:23 by emechali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	j;
	size_t	i;
	char	*line;

	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	line = malloc(sizeof(char) * (i + j + 1));
	if (line == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		line[i] = s1[i];
		i++;
	}
	while (s2[j])
		line[i++] = s2[j++];
	line[i] = '\0';
	return (line);
}

char	*ft_read(int fd, char *line)
{
	ssize_t	read_count;
	char	*buffer;
	char	*temp;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (free(line), NULL);
	read_count = -1;
	while (!ft_strchr(line, '\n') && read_count != 0)
	{
		read_count = read(fd, buffer, BUFFER_SIZE);
		if (read_count < 0)
			return (free(buffer), free(line), NULL);
		buffer[read_count] = '\0';
		temp = line;
		line = ft_strjoin(temp, buffer);
		free(temp);
		if (!line)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (line);
}

char	*ft_line_stop(char *line)
{
	size_t	i;
	size_t	j;
	char	*final_line;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	final_line = malloc(sizeof(char) * (i + 1));
	if (final_line == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		final_line[j] = line[j];
		j++;
	}
	final_line[j] = '\0';
	return (final_line);
}

char	*ft_rest(char *line, char *final_line)
{
	size_t	i;
	size_t	j;
	char	*rest;
	size_t	len;

	i = 0;
	while (final_line[i])
		i++;
	if (line[i] == '\0')
		return (free(line), NULL);
	len = i;
	while (line[len])
		len++;
	rest = malloc(sizeof(char) * (len - i + 1));
	if (!rest)
		return (free(line), NULL);
	j = 0;
	while (line[i])
	{
		rest[j++] = line[i++];
	}
	rest[j] = '\0';
	free(line);
	return (rest);
}
