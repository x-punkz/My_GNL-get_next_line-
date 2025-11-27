/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniviei <daniviei@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:32:37 by daniviei          #+#    #+#             */
/*   Updated: 2025/11/26 22:57:58 by daniviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#define MAX_FD 1024

void	found_line(t_list **holder)
{
	if (holder->str[i] == '\n')
		return (NULL);
}

static   void    join(t_list **holder, char *buffer)
{
	t_list  *new_node;
	t_list  *last_node;

	last_node = find_last_node(*holder);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*holder = last_node;
	else
		last_node->next = new_node;
	new_node->content = buffer
	new_node->next = NULL;
}

static void	create_list(t_list **holder, int fd)
{
	int     char_counted;
	char    *buffer;

	while (!found_line(*holder))
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof (char));
		if (!buffer)
			return (NULL);
		char_counted = read(fd, buffer, BUFFER_SIZE);
		if (!char_counted)
		{
			free(buffer);
			return;
		}
	}
	buffer[char_counted] = '\0';
	join(holder, buffer);
}

char	*get_next_line(int fd)
{
	static t_list	*holder;
	char		*next_line;

	holder = NULL;
	if (fd <= 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);

	create_list(&holder, fd);
	//
	void create_list(t_list **holder, int fd)
	{
		int	char_counted;
		char	*buffer;

		while (!found_line(*holder))
		{
			buffer = ft_calloc(BUFFER_SIZE + 1, sizeof (char));
			if (!buffer)
				return (NULL);
			char_counted = read(fd, buffer, BUFFER_SIZE);
			if (!char_counted)
			{
				free(buffer);
				return;
			}
		}
		buffer[char_counted] = '\0';
		join(holder, buffer);
		//
		void	join(t_list **holder, char *buffer)
		{
			t_list	*new_node;
			t_list	*last_node;

			last_node = find_last_node(*holder);
			new_node = malloc(sizeof(t_list));
			if (new_node == NULL)
				return ;
			if (last_node == NULL)
				*holder = last_node;
			else
				last_node->next = new_node;
			new_node->content = buffer
			new_node->next = NULL;
		}
		//
	}
	//
	if (!holder)
		return (NULL);
	next_line = get_line(holder);
	//
	char	get_line(t_list *holder)
	{
		int	str_len;
		char	*next_str;

		if (holder == NULL)
			return (NULL);
		str_len = len_to_next(holder);
		//por em ultils
		int	len_to_next(t_list *holder)
		{
			int	i;
			int	len;

			if (holder == NULL)
				return (NULL);
			len = 0;
			while (holder)
			{
				i = 0;
				while (holder->content[i])
				{
					if (holder->content[i] == '\n')
						++len;
					return (len);
					++i;
					++len;
				}
				holder = holder->next;
			}
			return (len);
		}
		//
		next_str = ft_calloc(str_len + 1,sizeof (char));
		if (!next_str)
			return (NULL);
		copy_str(holder, next_str);
		// tbm na utils
		char	copy_str(t_list *holder, char *str)
		{
			int	i;
			int	k;

			if (!holder)
				return ;
			k = 0;
			while (holder)
			{
				i = 0;
				while (holder->content[i])
				{
					if (holder->content[i] == '\n')//to aqui
					{
						str[k++] = '\n';
						str[k] = '\0';
						return ;
					}
					str[k++] = holder->content[i++];
				}
				holder = holder->next;
			}
			str[k] = '\0';
		}
		//
	}
	//

	polish_list(&holder);//polir a lista
	//
	void	polish_list(t_list **holder)
	{
		t_list	*last_node;
		t_list	*clean_node;
		int	i;
		int	k;
		char	*buff;

		buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		clean_node = malloc(sizeof(t_list));
		if (buff == NULL || clean_node == NULL)
			return ;
		last_node = find_last_node(*list);
		//
		find_last_node()
		//

		i = 0;
		k = 0;
		while (last_node->content[i] != '\0'
				&& last_node->content[i] != '\n')
			++i;
		while (last_node->content[i] != '\0'
				&& last_node->content[++i])
			buff[k++] = last_node->content[i];
		buff[k] = '\0';
		clean_node->content = buff;
		clean_node->next = NULL;
		dealloc(list, clean_node, buff);
		//
		dealloc()
		//
	}
	//
	return (next_line);
}

#include <stdio.h>
#include <fcntl.h>

int	main(void)
new{
	int	fd1;
	char	*linha1;
	
	fd1 = open("/home/daniviei/Desktop/gnl/arquivo.txt", O_RDONLY);

	linha1 = get_next_line(fd1);
	printf("L1 -> %s\n", linha1);
	free(linha1);
	linha1 = get_next_line(fd1);
	printf("L2 -> %s\n", linha1);
	free(linha2);
	linha1 = get_next_line(fd1);
	printf("L3 -> %s\n", linha1);
	free(linha1);
	linha1 = get_next_line(fd1);
	printf("L4 -> %s\n", linha1);
}
