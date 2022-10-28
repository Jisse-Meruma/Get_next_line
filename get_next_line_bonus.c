/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:52:21 by jisse             #+#    #+#             */
/*   Updated: 2022/10/28 17:21:24 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>
#include <fcntl.h>

/**
 * @brief 
 * Line_dup makes a string double the size of the one before. 
 * also make sure to free() the old line
 * other wise you'll have leaks :(
 */
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

/**
 * @brief 
 * This is the function that tells me if im at the end of a line.
 * if so i'll send a signal that i detect in my while loop to break the loop
 */
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

/**
 * @brief
 * First we have to see if the buffer exist.. aka is this the first call..
 * if so.. then we have to concatinate the old buffer to the new line.
 * Then well read into the buffer array with the amount of BUFFER_SIZE 
 * that is difined at compiling time. its very handy to keep count 
 * how many the read function actually read. 
 * so we can use this at are advantage. Then we have our read checks 
 * that tell me if the read failed or that we read the last chars
 * Then i check if i have to increase the size of the actual line 
 * if so i double the sizeof(line) that it was before :D.
 */
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

/**
 * @brief 
 * the Var line is the line wich we return after we found a (newline)
 * or are at the end of a file. if we are at the end of the file 
 * we have to make sure that the buffer array will be reset.
 * if we are not at the end of the file we have to trim the buffer 
 * so we can use it next time we call the function
 */
char	*get_next_line(int fd)
{
	char		*line;
	int			size_line;
	static char	buffer[OPEN_MAX][BUFFER_SIZE + 1];

	if (fd < 0 && fd <= OPEN_MAX)
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
