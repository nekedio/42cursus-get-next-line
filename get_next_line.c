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

static int get_pos_new_line(char *buf, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (buf[i] == '\n')
        {
            return i;
        }
        i++;
	}
	return i;
}

/* static int get_pos_new_line(char *buf, int len) */
/* { */
/* 	int i; */
/*  */
/* 	i = 0; */
/* 	while (i < len) */
/* 	{ */
/* 		if (buf[i] == '\n' && i != len - 1) */
/*         { */
/* 			//printf("---%d\n", len); */
/*             return i; */
/*         } */
/*         i++; */
/* 	} */
/* 	return 0; */
/* } */

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

	/* if (!s_buf || !str2) */
	/* 	return (NULL); */

    if (s_buf == NULL)
    {
        result = (char *)malloc(sizeof(result) * ft_strlen(str2) + 1);
	    counter = 0;
	    result = genstr(result, str2, &counter);
        return (result);
    }
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

static char				*ft_substr(char const *str, unsigned int start, size_t len)
{
	char			*result;
	size_t			i;
	size_t			j;
	unsigned int	str_len;

	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	if (start > str_len)
		return (ft_strdup(""));
	result = (char *)malloc(sizeof(*result) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = start;
	while (str[i] != '\0' && str_len > j && i < len)
	{
		result[i] = str[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}

int get_next_line(int fd, char **line)
{
	
	char buf[BUFFER_SIZE + 1];
	static char *s_buf;
	int str_len;
	int i;
    int mark;
    int isset_buf;

	isset_buf = 0;
    i = 0;
	//str_len = BUFFER_SIZE;

	*line = ft_calloc(sizeof(char), 1);
	/* if (s_buf == NULL) */
    /*     printf("!!! %s !!!\n", s_buf); // */
	//s_buf = "1";
    mark = BUFFER_SIZE;
	while (mark > 0)
	{
        printf("\n%d ---\n", i);
        printf("buf = %s\n", buf);
        //mark = read(fd, buf, BUFFER_SIZE);
        //buf[mark] = '\0';
        //printf("!%s!\n", buf);
        //printf("!%d!\n", mark);
        /* if (mark == 0) */
        /*     return (0); */
        //printf("!");
        //printf("!!! %d !!!\n", mark); 
		
        
        str_len = get_pos_new_line(buf, mark);
        printf("!%d!\n", str_len);
        if (str_len < mark)
        {
            printf("+");
            s_buf = ft_substr(buf, str_len + 1, BUFFER_SIZE - str_len);
            printf("line = %s\n", *line);
            printf("s_buf = %s\n", s_buf);
        }

        if (mark < BUFFER_SIZE)
        {
            *line = ft_strjoin(*line, buf);
        }

        //str_len = get_pos_new_line(buf);
        if (mark == BUFFER_SIZE)
        {
            *line = ft_strjoin(*line, buf);
            isset_buf = 0;
        }
        
        mark = read(fd, buf, BUFFER_SIZE);
        buf[mark] = '\0';

        //i++;
        //printf("!%d!\n", str_len);
		//buf[BUFFER_SIZE] = '\0';
        //printf("%d\n", str_len); //

        //s_buf = ft_substr(buf, str_len + 1, BUFFER_SIZE - str_len);
		//*line = ft_calloc(sizeof(char), str_len);
		//if (mark != 0)
        //{
        //ft_strlcpy(*line, buf, str_len + 1);
            //(*line)[str_len] = '*';
		//*line = ft_strjoin(s_buf, *line);
        
        //}
        //printf("!!!%s!!!\n", *line);
		//printf("!!! %s !!!\n", *line);
	    //printf("!");	
        //s_buf = ft_substr(buf, str_len + 1, BUFFER_SIZE - str_len);
        
        /* if (mark == 0) */
        /*     return (0); */
	    i++;
    }
    //s_buf = ft_substr(buf, str_len + 1, BUFFER_SIZE - str_len);
    //printf("///////////");
    return (0);
    //printf("!!! %s !!!\n", s_buf); //	
}
