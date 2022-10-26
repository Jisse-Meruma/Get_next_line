/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:11:23 by jmeruma           #+#    #+#             */
/*   Updated: 2022/10/26 17:40:20 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	*ptr;
	int		i;

	i = open("test.txt", O_RDONLY);
	ptr = get_next_line(i);
	printf("String = %s", ptr);
	ptr = get_next_line(i);
	printf("String = %s", ptr);
	ptr = get_next_line(i);
	printf("String = %s", ptr);
	ptr = get_next_line(i);
	printf("String = %s", ptr);
	while (!ptr)
	{
		ptr = get_next_line(i);
		printf("String = %s", ptr);
	}
	close(i);
}
