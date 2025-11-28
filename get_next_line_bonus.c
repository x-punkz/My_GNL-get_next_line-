/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniviei <daniviei@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:32:37 by daniviei          #+#    #+#             */
/*   Updated: 2025/11/25 21:13:58 by daniviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"
#define MAX_FD 1024

static char	*readed(char **h)
{
	char	*str;
	int		i;
	char	*tmp;
	
	i = 0;
	str = ft_calloc(ft_strlen(*h) + 2, sizeof(char));
	while (h[0][i] != '\0' && h[0][i] != '\n')
	{
		str[i] = h[0][i];
		i++;
	}
	if (h[0][i] == '\n')
		str[i++] = '\n';
	if (str[0] == '\0')
	{
		free(*h);
		free(str);
		*h = NULL;
		return(NULL);
	}
	tmp = ft_strdup(*h + i);
	free(*h);
	*h = tmp;
	return(str);
}

static char	*read_line(char **holder, int fd)
{
	char	*buffer;
	int		counter;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof (char));
	if (!buffer)
		return(NULL);
	while ((counter = read(fd, buffer, BUFFER_SIZE)))
	{
		if (counter == -1)
			break;
		buffer[counter] = '\0';
		*holder = ft_strjoin(holder, buffer);
		if (strchr(*holder, '\n'))
			break ;
	}
	free (buffer);
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
/*
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int	fd1;
	int	fd2;
	(void)argc;
	(void)argv;
	char	*linha1;
	char	*linha2;
	fd1 = open("arquivo.txt", O_RDONLY);
	fd2 = open("arquivo2.txt", O_RDONLY);

	linha1 = get_next_line(fd1);
	printf("L1 -> %s\n", linha1);
	free(linha1);
	linha2 = get_next_line(fd2);
	printf("L2 -> %s\n", linha2);
	free(linha2);
	
	linha1 = get_next_line(fd1);
	printf("L1 -> %s\n", linha1);
	free(linha1);
	linha2 = get_next_line(fd2);
	printf("L2 -> %s\n", linha2);
	free(linha2);
	
	linha1 = get_next_line(fd1);
	printf("L1 -> %s\n", linha1);
	free(linha1);
	linha2 = get_next_line(fd2);
	printf("L2 -> %s\n", linha2);
	free(linha2);
	
	linha1 = get_next_line(fd1);
	printf("L1 -> %s\n", linha1);
	free(linha1);
	linha2 = get_next_line(fd2);
	printf("L2 -> %s\n", linha2);
	free(linha2);
	
	close(fd1);
	close(fd2);
}*/
