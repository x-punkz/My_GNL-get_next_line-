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

void	free_all(t_list **list, t_list *clean_node, char *buffer)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->content);
		free((*list));
		*list = tmp;
	}
	*list = NULL;
	if (clean_node->content[0])
		*list = clean_node;
	else
	{
		free(buffer);
		free(clean_node);
	}
}

void	copy_list(t_list *list, char *str)
{
	int	i;
	int	j;

	j = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				str[j++] = '\n';
				str[j] = '\0';
				return ;
			}
			str[j++] = list->content[i++];
		}
		list = list->next;
	}
	str[j] = '\0';
}

int	len_to_newline(t_list *list)
{
	int	i;
	int	len;

	len = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				++len;
				return (len);
			}
			++i;
			++len;
		}
		list = list->next;
	}
	return (len);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	found_newline(t_list *holder)
{
	int	i;
	
	if (holder == NULL)
		return (0);
	while (holder)
	{
		i = 0;
		while (holder->content[i] && i < BUFFER_SIZE)
		{
			if (holder->content[i] == '\n')
				return (1);
			++i;
		}
		holder = holder->next;
	}
	return (0);
}

void    *ft_calloc(size_t nmemb, size_t size)
{
    void    *tab;
	size_t		i;

	i = 0;
	if (size != 0 && nmemb > SIZE_MAX / size)
                return (NULL);
        tab = malloc(size * nmemb);
        if (!tab)
                return (NULL);
        while (i < (size * nmemb))
		{
			((unsigned char *)tab)[i] = 0;
			i++;
		}
        return (tab);
}
