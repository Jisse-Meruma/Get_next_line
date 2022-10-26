/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:15:46 by jisse             #+#    #+#             */
/*   Updated: 2022/10/26 16:14:45 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	line_cat(char *line, char *buffer, int l_index)
{
	int			b_index;

	b_index = 0;
	while (b_index < BUFFER_SIZE && buffer[b_index] != '\n' && buffer[b_index])
	{
		line[l_index] = buffer[b_index];
		b_index++;
		l_index++;
	}
	if (buffer[b_index] == '\n')
	{
		line[l_index] = '\n';
		l_index++;
	}
	line[l_index] = '\0';
	return (l_index);
}

char	*malloc_creation(int *size_line)
{
	char	*line;

	*size_line *= BUFFER_SIZE;
	line = malloc(*size_line * sizeof(char) + 1);
	if (!line)
		return (NULL);
	line[*size_line] = '\0';
	return (line);
}

void	buffer_trim(char *buffer)
{
	int	b_index;
	int	b_reset;

	b_index = 0;
	b_reset = 0;
	while (buffer[b_index] != '\n')
		b_index++;
	if (buffer[b_index] == '\0')
		return ;
	b_index++;
	while (buffer[b_index])
	{
		buffer[b_reset] = buffer[b_index];
		b_index++;
		b_reset++;
	}
	while (b_reset < BUFFER_SIZE)
	{
		buffer[b_reset] = '\0';
		b_reset++;
	}
}
