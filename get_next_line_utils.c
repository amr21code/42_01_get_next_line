/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amr21code <a@n.de>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:04:56 by amr21code         #+#    #+#             */
/*   Updated: 2022/03/06 12:11:12 by amr21code        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str, char c)
{
	size_t	str_count;

	str_count = 0;
	while (str[str_count] != c)
	{
		str_count++;
	}
	return (str_count);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((char *)s + i) = '\0';
		i++;
	}
}

void	*ft_calloc(size_t elem, size_t elsize)
{
	void	*pointer;

	if (elem == 0)
		return (NULL);
	pointer = malloc(elem * elsize);
	if (pointer)
	{
		ft_bzero(pointer, elem * elsize);
	}
	return (pointer);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (*src)
		{
			dest[i] = *src;
			src++;
		}
		else
			dest[i] = '\0';
		i++;
	}
	return (dest);
}
