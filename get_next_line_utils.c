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

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *) malloc(sizeof (t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}	
	return (ptr);
}

void    *ft_calloc(size_t nmemb, size_t size)
{
        void    *tab;

	if (size != 0 && nmemb > SIZE_MAX / size)
                return (NULL);
        tab = malloc(size * nmemb);
        if (!tab)
                return (NULL);
        ft_memset(tab, 0, (size * nmemb));
        return (tab);
}
