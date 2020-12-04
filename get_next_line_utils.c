/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dxenophi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:52:58 by dxenophi          #+#    #+#             */
/*   Updated: 2020/12/04 20:43:58 by dxenophi         ###   ########.fr       */
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
