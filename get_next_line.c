/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:52:21 by jisse             #+#    #+#             */
/*   Updated: 2022/10/25 17:22:00 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#define BUFFER_SIZE  4

char	*buffer_checker(char *buffer, int *flag);
char	*line_dup(char	*line, int *n);
int		char_checker(char *buffer);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			n;
	int			counter;
	int			flag;

	n = 1;
	counter = 0;
	flag = 0;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	buffer = buffer_checker(buffer, &flag);
	if (!buffer)
		return (NULL);
	if (flag == 0)
		read(fd, buffer, BUFFER_SIZE);
	line = malloc_creation(&n);
	counter = line_cat(line, buffer);
	while (char_checker(buffer) != 1)
	{
		if (counter >= n)						/* Deze while loop graag in een andere funnctie :D*/
		{
			line = line_dup(line, &n);
		}
		if (!line)
			return (NULL);
		read(fd, buffer, BUFFER_SIZE);
		counter = line_cat(line, buffer);
	}
	// trim de line.. 
	return (line);
}

char	*line_dup(char	*line, int *n)
{
	int		i;
	char	*line_v2;
	
	i = 0;
	line_v2 = malloc_creation(n);
	if (!line_v2)
		return (NULL);
	while (line[i])
	{
		line_v2[i] = line[i];
		i++;
	}
	free(line);
	return (line_v2);
}

int	char_checker(char *buffer)
{
	int i;

	i = 0;
	while ((i < BUFFER_SIZE) && buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		return (1);
	return (0);
}

char	*buffer_checker(char *buffer, int *flag)
{
	if(!buffer)
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

int	main(void)
{
	char *ptr;
	int i;
	i = open("test.txt", O_RDONLY);
	ptr = get_next_line(i);
	close(i);
	printf("String = %s", ptr);
	//free(ptr);
}