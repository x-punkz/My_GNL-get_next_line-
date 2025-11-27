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

typedef struct	s_list;
{
	char			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);

#endif
