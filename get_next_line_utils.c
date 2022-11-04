/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:15:46 by jisse             #+#    #+#             */
/*   Updated: 2022/11/04 10:23:37 by jmeruma          ###   ########.fr       */
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

char	*calloc_creation(int *size_line)
{
	int		i;
	char	*line;

	i = 0;
	*size_line *= 2;
	line = malloc((*size_line) * sizeof(char) + 1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	return (line);
}

/**
 * @brief The functions buffer_trim allows me to change the string
 * so that i can reuse it the next time the function is getting called
 * ill go past the new-line then every char after the new-line will be
 * copied to the beginning of the buffer to be concatinated to the next
 * line if the function gets called again
 * @param buffer 
 */
void	buffer_trim(char *buffer)
{
	int	b_index;
	int	b_reset;

	b_index = 0;
	b_reset = 0;
	while (buffer[b_index] != '\n' && buffer[b_index])
		b_index++;
	if (buffer[b_index] == '\0')
	{
		buffer[0] = '\0';
		return ;
	}
	b_index++;
	while (buffer[b_index])
	{
		buffer[b_reset] = buffer[b_index];
		b_index++;
		b_reset++;
	}
	buffer[b_reset] = '\0';
}

char	*malloc_trim(char *line)
{
	int		i;
	int		size;
	char	*final_line;

	i = 0;
	size = ft_strlen(line);
	final_line = malloc((sizeof(char) * size) + 1);
	if (!final_line)
		return (free(line), NULL);
	while (line[i])
	{
		final_line[i] = line[i];
		i++;
	}
	final_line[i] = '\0';
	free(line);
	return (final_line);
}

int	ft_strlen(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
		i++;
	return (i);
}
