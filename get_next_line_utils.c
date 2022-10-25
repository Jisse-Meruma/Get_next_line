/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:15:46 by jisse             #+#    #+#             */
/*   Updated: 2022/10/25 16:35:54 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 4

int	line_cat(char *dest, char *src)
{
	static int i;
	int len;
	int j;
	
	j = 0;
	while (j < BUFFER_SIZE)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	return (i);
}

char	*malloc_creation(int *n)
{
	char		*ptr;

	*n *= BUFFER_SIZE;
	ptr = malloc(*n  * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	ptr[*n] = '\0';
	return (ptr);
}
