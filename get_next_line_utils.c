/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:15:46 by jisse             #+#    #+#             */
/*   Updated: 2022/10/27 17:23:27 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	line_cat(char *line, char *buffer, int l_index, int read_count)
{
	int			b_index;

	b_index = 0;
	while (b_index < read_count && buffer[b_index] != '\n')
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

	line = malloc((*size_line) * sizeof(char) + 1);
	if (!line)
		return (NULL);
	line[*size_line] = '\0';
	*size_line *= 2;
	return (line);
}

void	buffer_trim(char *buffer)
{
	int	b_index;
	int	b_reset;

	b_index = 0;
	b_reset = 0;
	while (buffer[b_index] != '\n' && buffer[b_index])
		b_index++;
	b_index++;
	if (buffer[b_index] == '\0')
	{
		buffer[0] = '\0';
		return ;
	}
	while (buffer[b_index])
	{
		buffer[b_reset] = buffer[b_index];
		b_index++;
		b_reset++;
	}
	buffer[b_reset] = '\0';
}

int	ft_strlen(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
		i++;
	return (i);
}
