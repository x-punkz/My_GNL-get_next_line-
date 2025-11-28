/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniviei <daniviei@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 19:11:35 by daniviei          #+#    #+#             */
/*   Updated: 2025/11/26 12:13:32 by daniviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdint.h>
# include <fcntl.h>

typedef struct	s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
void    *ft_calloc(size_t nmemb, size_t size);
int		found_newline(t_list *holder);
t_list	*ft_lstlast(t_list *lst);
int		len_to_newline(t_list *list);
void	copy_list(t_list *list, char *str);
void	free_all(t_list **list, t_list *clean_node, char *buffer);

#endif
