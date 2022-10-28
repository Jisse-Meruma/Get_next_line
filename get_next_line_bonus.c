/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:52:21 by jisse             #+#    #+#             */
/*   Updated: 2022/10/28 13:48:27 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*line_dup(char	*line, int *size_line)
{
	int		i;
	int		size_old;
	char	*line_v2;

	i = 0;
	size_old = *size_line;
	line_v2 = calloc_creation(size_line);
	if (!line_v2)
		return (NULL);
	while (i < size_old)
	{
		line_v2[i] = line[i];
		i++;
	}
	free(line);
	return (line_v2);
}

int	char_checker(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		return (1);
	return (0);
}

char	*line_assembly(char *buffer, int fd, char *line, int *size_line)
{
	int		counter;
	int		read_count;

	counter = 0;
	while (char_checker(buffer) != 1)
	{
		if (*buffer != 0)
			counter = line_cat(line, buffer, counter, ft_strlen(buffer));
		read_count = read(fd, buffer, BUFFER_SIZE);
		if (read_count == -1)
			return (free(line), NULL);
		if (read_count < BUFFER_SIZE)
		{
			if (read_count == 0 && *line == '\0')
				return (free(line), NULL);
			buffer[read_count] = '\0';
			counter = line_cat(line, buffer, counter, ft_strlen(buffer));
			return (line);
		}
		if (counter >= (*size_line - BUFFER_SIZE) && *buffer != 0)
			line = line_dup(line, size_line);
		if (!line)
			return (NULL);
	}
	return (line_cat(line, buffer, counter, ft_strlen(buffer)), line);
}

char	*get_next_line(int fd)
{
	char		*line;
	int			size_line;
	static char	buffer[4096][BUFFER_SIZE + 1];

	if (fd < 0)
		return (NULL);
	size_line = BUFFER_SIZE;
	line = calloc_creation(&size_line);
	if (!line)
		return (NULL);
	line = line_assembly(buffer[fd], fd, line, &size_line);
	if (!line)
	{
		buffer[fd][0] = '\0';
		return (NULL);
	}
	buffer_trim(buffer[fd]);
	return (line);
}
