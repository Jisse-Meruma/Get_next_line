/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:15:46 by jisse             #+#    #+#             */
/*   Updated: 2022/10/24 16:17:31 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 4

void	str_cpy(char *dest, char *src)
{
	int			len;
	int			i;
	static int	n;
	
	i = 0;
	len = n++ * BUFFER_SIZE;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
}

void	str_cat(char *dest, char *src)
{
	static int i;
	int len;
	int j;
	
	j = 0;
	i += BUFFER_SIZE;
	while (j < BUFFER_SIZE && src[i] != '\n')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (src[i] == '\n')
		dest[i] = '\n';
}

void	last_cpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\n' && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
	{
		dest[i] = '\n';
		i++;
	}
	dest[i] = '\0';
}
