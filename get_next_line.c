/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dxenophi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:27:21 by dxenophi          #+#    #+#             */
/*   Updated: 2020/12/08 22:42:22 by dxenophi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char			*ft_strdup(const char *str)
{
	char		*result;

	result = (char *)malloc(ft_strlen(str) + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, str, ft_strlen(str) + 1);
	return (result);
}

static int		processing_s_buf(char **s_buf, char **line)
{
	char		*after_new_line;

	if (*s_buf)
		if ((after_new_line = ft_strchr(*s_buf, '\n')) != NULL)
		{
			*after_new_line = '\0';
			*line = ft_strdup(*s_buf);
			ft_strlcpy(*s_buf, after_new_line + 1,
					ft_strlen(after_new_line + 1) + 1);
			return (1);
		}
		else
		{
			*line = ft_strdup(*s_buf);
			free(*s_buf);
			*s_buf = NULL;
		}
	else
	{
		*line = (char *)malloc(sizeof(*line) * 1);
		if (*line == NULL)
			return (0);
		*line[0] = '\0';
	}
	return (0);
}

static int		processing_buf(char **buf, char **s_buf)
{
	char		*after_new_line;

	after_new_line = ft_strchr(*buf, '\n');
	if (after_new_line)
	{
		*after_new_line = '\0';
		*s_buf = ft_strdup(after_new_line + 1);
		return (1);
	}
	return (0);
}

static int		ft_read(int fd, char **s_buf, char **line, int *new_line_in_buf)
{
	int			len_read;
	char		*temp;
	char		*buf;

	len_read = 1;
	while (len_read > 0 && *new_line_in_buf == 0)
	{
		buf = (char *)malloc(sizeof(buf) * (BUFFER_SIZE + 1));
		if (!buf)
			return (0);
		if ((len_read = read(fd, buf, BUFFER_SIZE)) < 1)
		{
			free(*s_buf);
			*s_buf = NULL;
			free(buf);
			return (len_read);
		}
		buf[len_read] = '\0';
		*new_line_in_buf = processing_buf(&buf, s_buf);
		temp = *line;
		*line = ft_strjoin(*line, buf);
		free(temp);
		free(buf);
	}
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char	*s_buf;
	int			new_line_in_buf;
	int			result;

	if (BUFFER_SIZE < 1 || line == NULL)
	{
		return (-1);
	}
	new_line_in_buf = processing_s_buf(&s_buf, line);
	result = ft_read(fd, &s_buf, line, &new_line_in_buf);
	if (*line == NULL)
	{
		return (-1);
	}
	return (result);
}
