/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:15:46 by jisse             #+#    #+#             */
/*   Updated: 2022/10/28 17:26:56 by jmeruma          ###   ########.fr       */
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
	while (i <= *size_line)
	{
		line[i] = '\0';
		i++;
	}
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

int	ft_strlen(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
		i++;
	return (i);
}
