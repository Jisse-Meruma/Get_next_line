/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:15:49 by jisse             #+#    #+#             */
/*   Updated: 2022/10/27 16:45:08 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# if BUFFERSIZE < 1
#  undef BUFFER_SIZE
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*get_next_line(int fd);

char	*malloc_creation(int *size_len);
int		ft_strlen(char *buffer);
int		line_cat(char *line, char *buffer, int size_len, int read_count);
void	buffer_trim(char *buffer);

#endif
