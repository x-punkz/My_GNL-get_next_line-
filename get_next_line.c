/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniviei <daniviei@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:32:37 by daniviei          #+#    #+#             */
/*   Updated: 2025/11/19 15:44:46 by daniviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <string.h>
#include <fcntl.h>
#define MAX_FD 1024

char	*readed(char **h)
{
	char	*str;
	int		i;
	char	*tmp;
	
	i = -1;
	str = ft_calloc(ft_strlen(*h) + 2, sizeof(char));
	while (h[0][i] && h[0][++i] != '\n')//ta quebrando aqui
		str[i] = h[0][i];
	if (h[0][i] == '\n')
		str[i++] = '\n';
	if (h[0][i] == '\0')
	{
		free(*h);
		*h = NULL;
		return(str);
	}
	tmp = ft_strdup(*h + i);
	free(*h);
	*h = tmp;
	return(str);
}

char	*read_line(char **holder, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		counter;

	while ((counter = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[counter] = '\0';
		*holder = ft_strjoin(holder, buffer);
		if (strchr(*holder, '\n'))
			break ;
	}
	return (readed(holder));
}

char	*get_next_line(int fd)
{
	static char	*holder[MAX_FD];

	if (fd <= 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!holder[fd])
		holder[fd] = ft_calloc(1, 1);
	return (read_line(&holder[fd], fd));
}

#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int	fd1;
	int	fd2;
	(void)argc;
	char	*linha1;
	char	*linha2;
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	linha1 = ft_calloc(1, 1);;
	linha2 = ft_calloc(1, 1);;
	while (linha1 || linha2)
	{
		free(linha1);
		free(linha2);
		linha1 = get_next_line(fd1);
		linha2 = get_next_line(fd2);
		printf("arquivo 1: %s \nlinha2: %s\n", linha1, linha2);
	}
}