/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniviei <daniviei@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 19:27:34 by daniviei          #+#    #+#             */
/*   Updated: 2025/11/26 12:27:45 by daniviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static void	polish_list(t_list	**holder)
{
	int		i;
	int		j;
	t_list	*last_node;
	t_list	*clean_node;
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (buff == NULL || clean_node == NULL)
		return ;
	last_node = ft_lstlast(*holder);
	i = 0;
	j = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		i++;
	while (last_node->content[i] && last_node->content[++i])
		buff[j++] = last_node->content[i];
	buff[j] = '\0';
	clean_node->content = buff;
	clean_node->next = NULL;
	free_all(holder, clean_node, buff);
}

static char	*get_line(t_list *holder)
{
	int		len;
	char	*next_str;

	len = len_to_newline(holder);
	next_str = malloc(len + 1);
	if (next_str == NULL)
		return (NULL);
	copy_list(holder, next_str);
	return (next_str);
}

static void	join(t_list **holder, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = ft_lstlast(*holder);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*holder = new_node;
	else
		last_node->next = new_node;
	new_node->content = buf;
	new_node->next = NULL;
}

static void	create_list(t_list **holder, int fd)
{
	char	*buff;
	int		char_read;

	while (!found_newline(*holder))
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (buff == NULL)
			return ;
		char_read = read(fd, buff, BUFFER_SIZE);
		if (!char_read)
		{
			free(buff);
			return ;
		}
		buff[char_read] = '\0';
		join(holder, buff);
	}

}
char	*get_next_line(int fd)
{
	static t_list	*holder = NULL;
	char	*str;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	create_list(&holder, fd);
	if (holder == NULL)
		return (NULL);
	str = get_line(holder);
	polish_list(&holder);
	return (str);
}

#include <stdio.h>
int	main(void)
{
	int	fd;
	char *line;
	int	lines;

	lines  = 1;
	fd = open("arquivo.txt", O_RDONLY);

	while ((line = get_next_line(fd))

)
	{
		printf("linha %d -> %s\n", lines, line);
		lines++;
		free(line);
	}
	return (0);
}