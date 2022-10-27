/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:52:21 by jisse             #+#    #+#             */
/*   Updated: 2022/10/27 17:30:12 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*line_assembly(char *buffer, int fd, int char_read, int *flag);
char	*line_dup(char	*line, int *size_line);
int		char_checker(char *buffer);

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			flag;
	char		*line;
	int			read_count;

	read_count = 1;
	flag = 0;
	if (fd < 1)
		return (NULL);
	if (*buffer != 0)
		read_count = ft_strlen(buffer);
	line = line_assembly(buffer, fd, read_count, &flag);
	if (!line)
		return (NULL);
	buffer_trim(buffer);
	return (line);
}

char	*line_assembly(char *buffer, int fd, int read_count, int *flag)
{
	int		counter;
	int		size_line;
	char	*line;
	
	counter = 0;
	size_line = BUFFER_SIZE;
	line = malloc_creation(&size_line);
	while (char_checker(buffer) != 1)
	{
		if (*buffer != 0)
			counter = line_cat(line, buffer, counter, read_count);
		read_count = read(fd, buffer, BUFFER_SIZE);
		if (read_count == -1)
			return (free(line), NULL);
		if (read_count < BUFFER_SIZE)
		{
			*flag = 1;
			// IS ER WEL GENOEG SPACE FOR THE CAT..... 
			counter = line_cat(line, buffer, counter, read_count);
			return (line);
		}
		if (counter >= (size_line - BUFFER_SIZE) && *buffer != 0)
			line = line_dup(line, &size_line);
		if (!line)
			return (NULL);
	}
	counter = line_cat(line, buffer, counter, read_count);
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
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		return (1);
	return (0);
}
