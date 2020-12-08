/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dxenophi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:52:58 by dxenophi          #+#    #+#             */
/*   Updated: 2020/12/07 17:58:41 by dxenophi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize)
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
	dst[i] = '\0';
	return (len_src);
}

char				*ft_strchr(const char *str, int chr)
{
	char			*ft_str;
	int				i;

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

size_t				ft_strlen(const char *src)
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

char				*ft_strjoin(char const *s_buf, char const *str2)
{
	unsigned int	sum_str;
	char			*result;
	unsigned int	counter;

	if (!s_buf || !str2)
		return (NULL);
	sum_str = ft_strlen(s_buf) + ft_strlen(str2);
	result = (char *)malloc(sizeof(result) * sum_str + 1);
	if (!result || !s_buf || !str2)
		return (NULL);
	counter = 0;
	result = genstr(result, s_buf, &counter);
	result = genstr(result, str2, &counter);
	return (result);
}
