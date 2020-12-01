/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dxenophi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:27:21 by dxenophi          #+#    #+#             */
/*   Updated: 2020/12/01 20:18:25 by dxenophi         ###   ########.fr       */
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
	
	char buf[BUFFER_SIZE];
	static char *s_buf;
	int str_len;
	int i;

	i = 0;
	str_len = BUFFER_SIZE;

	*line = ft_calloc(sizeof(char), 1);
	//printf("%s\n", *line); //
	//s_buf = "";
	while (str_len >= BUFFER_SIZE)
	{
		read(fd, buf, BUFFER_SIZE);
		str_len = get_nul_term(buf);
		//printf("%d\n", str_len); //

		*line = ft_calloc(sizeof(char), str_len);
		ft_strlcpy(*line, buf, str_len + 1);
		*line = ft_strjoin(s_buf, *line);
		printf("%s\n", *line);
		i++;
	}
	s_buf = ft_substr(buf, str_len + 1, BUFFER_SIZE - str_len);
	//printf("!!! %s !!!\n", s_buf); //	
}

int get_next_line(int fd, char **line)
{
	//int i = 0;
	
	get_str(fd, line);
	return (0);
}
