/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:11:23 by jmeruma           #+#    #+#             */
/*   Updated: 2022/10/27 17:07:39 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	*ptr;
	int		i;

	i = open("test.txt", O_RDONLY);
	ptr = get_next_line(i);
	while (ptr != NULL)
	{
		printf("String:\t|%s", ptr);
		free(ptr);
		ptr = get_next_line(i);
		
	}
}
