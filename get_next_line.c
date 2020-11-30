/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dxenophi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:27:21 by dxenophi          #+#    #+#             */
/*   Updated: 2020/11/30 21:50:02 by dxenophi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> //

static int get_nul_term(char *buf)
{
	int i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buf[i] == '\n')
			return i;
		i++;
	}
	return i;
}

static void get_str(int fd, char **line)
{
	char buffer[BUFFER_SIZE];
	int str_len;
	int i;

	i = 0;
	str_len = BUFFER_SIZE;

	*line = ft_calloc(sizeof(char), 1);
	//printf("%s\n", *line); //

	while (str_len >= BUFFER_SIZE)
	{
		read(fd, buffer, BUFFER_SIZE);
		str_len = get_nul_term(buffer);
		printf("%d\n", str_len); //

		*line = ft_calloc(sizeof(char), str_len);
		ft_strlcpy(*line, buffer, str_len + 1);
		printf("%s\n", *line);
		i++;
	}
}

int get_next_line(int fd, char **line)
{
	int i = 0;
	
	get_str(fd, line);
	return (0);
}
