/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniviei <daniviei@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 19:11:35 by daniviei          #+#    #+#             */
/*   Updated: 2025/11/18 19:57:32 by daniviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

char	*get_next_line(int fd);
char    *ft_strjoin(char **s1, char *s2);
size_t  ft_strlen(char *str);
char    *ft_strdup(char *s);
char	*readed(char **r);
void	*ft_memset(void *s, int c, size_t n);
void    *ft_calloc(size_t nmemb, size_t size);

#endif
