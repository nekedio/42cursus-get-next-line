/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dxenophi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:52:43 by dxenophi          #+#    #+#             */
/*   Updated: 2020/12/01 16:41:43 by dxenophi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int i;
	int j;
	int fd;
    int mark;
	char *line;

	i = 1;
	if (argc < 2)
	{
		get_next_line(1, &line);
		printf("%s\n", line);
	}
	else
	{
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			j = 0;
            mark = 1;
            while (mark != 0)
			{
				mark = get_next_line(fd, &line);
			    printf("     > %s\n", line);
                printf("----------\n");
			}
			i++;
		}
	}
}
