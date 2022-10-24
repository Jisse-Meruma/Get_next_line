/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:52:21 by jisse             #+#    #+#             */
/*   Updated: 2022/10/24 17:11:52 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#define BUFFER_SIZE  4

char	*malloc_creation(void);
int	char_checker(char *ptr);

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*str;
	int			i;
	int			counter;
	

	i = 0;
	counter = 0;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = malloc_creation();
		if (!buffer)
			return (NULL);
		read(fd, buffer, BUFFER_SIZE);
	}
	while (char_checker(buffer) != 1)
	{
		
		if (counter >= i)
		{
			str = malloc_creation();
			i *= BUFFER_SIZE;
		}
		read(fd, buffer, BUFFER_SIZE);
		str_cat(str, buffer);
		counter += BUFFER_SIZE;
	}
	return (str);
}

char	*malloc_creation(void)
{
	char		*ptr;
	static int	n;

	n *= BUFFER_SIZE;
	ptr = malloc(n * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	return (ptr);
}

int	char_checker(char *ptr)
{
	int i;
	static int n;

	i = 0;
	while ((i < BUFFER_SIZE * n++) && ptr[i] != '\n' && ptr[i])
		i++;
	if (ptr[i] == '\n')
		return (1);
	return (0);
}

int	main(void)
{
	char *ptr;
	int i;
	i = open("test.txt", O_RDONLY);
	ptr = get_next_line(i);
	close(i);
	printf("aa = %s", ptr);
	//free(ptr);
}