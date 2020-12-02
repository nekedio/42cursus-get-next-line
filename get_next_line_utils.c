/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dxenophi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:52:58 by dxenophi          #+#    #+#             */
/*   Updated: 2020/12/01 20:02:49 by dxenophi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *src)
{
	char			*ft_src;
	size_t			i;

	i = 0;
	ft_src = (char *)src;
	while (ft_src[i] != '\0')
	{
		i++;
	}
	return (i);
}

/* static char				*ft_strdup(const char *str) */
/* { */
/* 	char			*result; */
/*  */
/* 	result = (char *)malloc(ft_strlen(str) + 1); */
/* 	if (!result) */
/* 		return (NULL); */
/* 	ft_strlcpy(result, str, ft_strlen(str) + 1); */
/* 	return (result); */
/* } */

/* char				*ft_substr(char const *str, unsigned int start, size_t len) */
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
/* 	result[i] = '\0'; // */
/* 	return (result); */
/* } */

static void			*ft_bzero(void *arr, size_t size)
{
	size_t			i;
	unsigned char	*result;

	i = 0;
	result = (unsigned char *)arr;
	while (i < size)
	{
		result[i] = '\0'; //
		i++;
	}
	return (result);
}

void		*ft_calloc(size_t count, size_t size)
{
	void	*result;

	if (!count || !size)
	{
		count = 1;
		size = 1;
	}
	result = (void *)malloc(count * size);
	if (!result)
	{
		return (NULL);
	}
	ft_bzero(result, count * size);
	return (result);
}


size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			len_src;
	size_t			i;

	if (!dst || !src)
		return (0);
	len_src = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (len_src);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0'; //
	return (len_src);
}
