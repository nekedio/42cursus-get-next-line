/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dxenophi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:52:43 by dxenophi          #+#    #+#             */
/*   Updated: 2020/12/08 22:20:15 by dxenophi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>
#include "get_next_line.h"
void			put(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
}

void			print_er(int *er, char *name, char *arg)
{
	put(basename(name));
	write(1, ": ", 2);
	put(arg);
	write(1, ": ", 2);
	put(strerror(*er));
	write(1, "\n", 1);
	*er = 0;
}

void			print_norm(int fb)
{
	char		buffer[1];

	while (read(fb, buffer, 1) > 0)
	{
		write(1, buffer, 1);
	}
}

void			print_file(char *item, char *name)
{
	int			fd;
	int			rr;
	char		buffer[1];

	if ((fd = open(item, O_RDONLY)) == -1)
	{
		print_er(&errno, name, item);
		return ;
	}
	while ((rr = read(fd, buffer, 1)) > 0)
	{
		write(1, buffer, 1);
	}
	if (rr < 0)
	{
		print_er(&errno, name, item);
	}
}
int	main(int argc, char **argv)
{
	int i;
	int fd;
	int gnl;

    /* int gnl0; */
	/* int gnl1; */
	/* int gnl2; */
	/* int gnl3; */
	
	char *line;

	i = 1;
	if (argc < 2)
	{
		gnl = 1;
		while (gnl > 0)
		{
			gnl = get_next_line(1, &line);
			printf("     > %s\n", line);
			printf("> %d\n", gnl);
		}
	}
	else
	{
		while (i < argc)
		{
			printf("---------------%s----------------\n", argv[i]);
			fd = open(argv[i], O_RDONLY);

			gnl = 1;
			while (gnl > 0)
			{
				gnl = get_next_line(fd, &line);
				printf("> %s\n", line);
				//printf("> %d\n", gnl);
				free(line);
			}
		
			/* gnl0 = get_next_line(fd, &line); 	 */
			/* printf("     >line0 = %s\n", line); */
			/* printf("return gnl0 = %d\n", gnl0); */
			/* printf("------------\n"); */
			/* gnl1 = get_next_line(fd, &line);  */
			/* printf("     >line1 = %s\n", line); */
			/* printf("return gnl1 = %d\n", gnl1); */
			/* printf("------------\n"); */
			/* gnl2 = get_next_line(fd, &line);  */
			/* printf("     >line2 = %s\n", line); */
			/* printf("return gnl2 = %d\n", gnl2); */
			/* printf("------------\n"); */
			/* gnl3 = get_next_line(fd, &line);  */
			/* printf("     >line3 = %s\n", line); */
			/* printf("return gnl3 = %d\n", gnl3); */


		printf("\n\n");
			print_file(argv[i], argv[0]);

			i++;
			close(fd);
		}
		
		printf("-------------------------------------------\n");
	}
	return (0);
}
