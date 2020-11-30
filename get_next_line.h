/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dxenophi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:32:42 by dxenophi          #+#    #+#             */
/*   Updated: 2020/11/30 21:32:42 by dxenophi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *str);
void	*ft_calloc(size_t count, size_t size);
size_t      ft_strlcpy(char *dst, const char *src, size_t dstsize);
char                *ft_strjoin(char const *str1, char const *str2);

#endif