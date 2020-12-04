/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dxenophi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:27:21 by dxenophi          #+#    #+#             */
/*   Updated: 2020/12/04 21:23:28 by dxenophi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> //

/* static int get_pos_new_line(char *buf, int len) */
/* { */
/* 	int i; */
/*  */
/* 	i = 0; */
/* 	while (i < len) */
/* 	{ */
/* 		if (buf[i] == '\n') */
/*         { */
/*             return i; */
/*         } */
/*         i++; */
/* 	} */
/* 	return i; */
/* } */

char		*ft_strchr(const char *str, int chr)
{
	char	*ft_str;
	int		i;

	ft_str = (char *)str;
	i = 0;
	while (ft_str[i])
	{
		if (ft_str[i] == chr)
		{
			return (ft_str + i);
		}
		i++;
	}
	if (ft_str[i] == '\0' && chr == '\0')
	{
		return (ft_str + i);
	}
	return (NULL);
}

static size_t		ft_strlen(const char *src)
{
	char	*ft_src;
	size_t	i;

	i = 0;
	ft_src = (char *)src;
	while (ft_src[i] != '\0')
	{
		i++;
	}
	return (i);
}

static char			*genstr(char *dst, char const *srt, unsigned int *counter)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = *counter;
	while (srt[i])
	{
		dst[j] = srt[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	*counter = j;
	return (dst);
}

static char				*ft_strjoin(char const *s_buf, char const *str2)
{
	unsigned int	sum_str;
	char			*result;
	unsigned int	counter;

	if (!s_buf || !str2)
		return (NULL);

    /* if (s_buf == NULL) */
    /* { */
    /*     result = (char *)malloc(sizeof(result) * ft_strlen(str2) + 1); */
	/*     counter = 0; */
	/*     result = genstr(result, str2, &counter); */
    /*     return (result); */
    /* } */
    sum_str = ft_strlen(s_buf) + ft_strlen(str2);
	result = (char *)malloc(sizeof(result) * sum_str + 1);
	if (!result || !s_buf || !str2)
		return (NULL);
	counter = 0;
	result = genstr(result, s_buf, &counter);
	result = genstr(result, str2, &counter);
	return (result);
}

static char		*ft_strdup(const char *str)
{
	char	*result;

	result = (char *)malloc(ft_strlen(str) + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, str, ft_strlen(str) + 1);
	return (result);
}

/* static char				*ft_substr(char const *str, unsigned int start, size_t len) */
/* { */
/* 	char			*result; */
/* 	size_t			i; */
/* 	size_t			j; */
/* 	unsigned int	str_len; */
/*  */
/* 	if (!str) */
/* 		return (NULL); */
/* 	str_len = ft_strlen(str); */
/* 	if (start > str_len) */
/* 		return (ft_strdup("")); */
/* 	result = (char *)malloc(sizeof(*result) * (len + 1)); */
/* 	if (!result) */
/* 		return (NULL); */
/* 	i = 0; */
/* 	j = start; */
/* 	while (str[i] != '\0' && str_len > j && i < len) */
/* 	{ */
/* 		result[i] = str[j]; */
/* 		i++; */
/* 		j++; */
/* 	} */
/* 	result[i] = '\0'; */
/* 	return (result); */
/* } */

void	ft_strclr(char *s)
{
	if (s)
	{
		while (*s)
		{
			*s = '\0';
			s++;
		}
	}
}

char	*my_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int get_next_line(int fd, char **line)
{
	char buf[BUFFER_SIZE + 1];
	int len_read;
	char *after_new_line;
	static char *s_buf;
	char *after_new_line1;
	int new_line_in_buf;
	char *temp;

	if (BUFFER_SIZE < 1)
		return (-1);

	new_line_in_buf = 0;
	len_read = BUFFER_SIZE;
	if (s_buf)
	{
		after_new_line1 = ft_strchr(s_buf, '\n');
		//printf("s_buf = %s\n", s_buf);
		//printf("s_buf = %s\n", after_new_line1);
		if (after_new_line1)
		{
			*after_new_line1 = '\0';
			*line  = ft_strdup(s_buf);
			//printf("!%s = %zu!\n", s_buf, ft_strlen(s_buf));
			ft_strlcpy(s_buf, after_new_line1 + 1, ft_strlen(after_new_line1 + 1) + 1);
			//my_strcpy(s_buf, after_new_line1 + 1);
			new_line_in_buf = 1;
		}
		else
		{
			*line  = ft_strdup(s_buf);
			free(s_buf);
			s_buf = NULL;
		}
	}
	else
	{
		*line = ft_calloc(sizeof(char), 1); 
	}


	while (len_read > 0 && new_line_in_buf == 0)
	{
		len_read = read(fd, buf, BUFFER_SIZE);
		if (len_read < 1)
			return (len_read);
		buf[len_read] = '\0';
		
		after_new_line = ft_strchr(buf, '\n');
		if (after_new_line)
		{
			*after_new_line = '\0';
			new_line_in_buf = 1;
			s_buf = ft_strdup(after_new_line + 1);
		}
		
		temp = *line;	
		*line = ft_strjoin(*line, buf);
		free(temp);
	}
	return (1);
}

