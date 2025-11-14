/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniviei <daniviei@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:32:37 by daniviei          #+#    #+#             */
/*   Updated: 2025/11/14 19:35:39 by daniviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	char	buffer[1];

	buffer = (char) malloc(sizeof (BUFFER_SIZE));
	if(!buffer)
		return (NULL);
	
}
