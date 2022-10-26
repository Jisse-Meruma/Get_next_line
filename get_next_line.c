/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:52:21 by jisse             #+#    #+#             */
/*   Updated: 2022/10/26 18:58:15 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*buffer_checker(char *buffer, int *flag);
char	*line_assembly(char *buffer, int fd);
char	*line_dup(char	*line, int *size_line);
int		char_checker(char *buffer);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;	
	int			flag;

	flag = 0;
	if (BUFFER_SIZE < 1 || fd < 1)
		return (NULL);
	buffer = buffer_checker(buffer, &flag);
	if (!buffer)
		return (NULL);
	if (flag == 0)
	{
		if (read(fd, buffer, BUFFER_SIZE) == 0)
		{
			free(buffer);
			return (NULL);
		}
	}
	line = line_assembly(buffer, fd);
	if (!line)
		return (NULL);
	buffer_trim(buffer);
	return (line);
}

char	*line_assembly(char *buffer, int fd)
{
	int		counter;
	int		size_line;
	char	*line;
	
	size_line = 1;
	line = malloc_creation(&size_line);
	counter = line_cat(line, buffer, 0);
	while (char_checker(buffer) != 1)
	{
		if (counter >= size_line)
			line = line_dup(line, &size_line);
		if (!line)
			return (NULL);
		if (read(fd, buffer, BUFFER_SIZE) == 0)
		{
			free(buffer);
			return (NULL);
		} 
		counter = line_cat(line, buffer, counter);
	}
	return (line);
}

char	*line_dup(char	*line, int *size_line)
{
	int		i;
	char	*line_v2;

	i = 0;
	line_v2 = malloc_creation(size_line);
	if (!line_v2)
		return (NULL);
	while (line[i])
	{
		line_v2[i] = line[i];
		i++;
	}
	line_v2[i] = line[i];
	free(line);
	return (line_v2);
}

int	char_checker(char *buffer)
{
	int	i;

	i = 0;
	while ((i < BUFFER_SIZE) && buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n' || (buffer[i] == '\0' && i < BUFFER_SIZE))
		return (1);
	return (0);
}

char	*buffer_checker(char *buffer, int *flag)
{
	if (!buffer)
	{
		buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
		if (!buffer)
			return (NULL);
		buffer[BUFFER_SIZE] = '\0';
		return (buffer);
	}
	else
		*flag = -1;
	return (buffer);
}
