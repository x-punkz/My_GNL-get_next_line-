/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniviei <daniviei@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 19:27:34 by daniviei          #+#    #+#             */
/*   Updated: 2025/11/25 19:25:55 by daniviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*ft_strjoin(char **s1, char *s2)
{
	int		i;
	int		ni;
	size_t	size;
	char	*nstr;

	i = 0;
	ni = 0;
	size = (ft_strlen(s1[0]) + ft_strlen(s2)) * sizeof(char);
	nstr = (char *)malloc(size + 1);
	if (!nstr)
		return (NULL);
	while (s1[0][i] != '\0')
	{
		nstr[ni] = s1[0][i];
		ni++;
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		nstr[ni++] = s2[i++];
	}
	nstr[ni] = '\0';
	free(s1[0]);
	return (nstr);
}

char	*ft_strdup(char *s)
{
	char	*dest;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(s);
	dest = (char *) malloc(sizeof (char) * (size + 1));
	if (!dest)
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
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
