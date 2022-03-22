/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:04:56 by anruland         #+#    #+#             */
/*   Updated: 2022/03/22 10:17:10 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	str_count;

	str_count = 0;
	while (str[str_count] != '\0')
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

void	ft_bzero(void *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		*((char *)s + i) = '\0';
		i++;
	}
}

void	*ft_calloc(int elem, int elsize)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size_s1;
	int		size_s2;
	int		i;
	char	*concat;

	i = 0;
	size_s1 = ft_strlen((char *)s1);
	size_s2 = ft_strlen((char *)s2);
	concat = (char *)malloc(sizeof(char) * (size_s1 + size_s2 + 1));
	if (!concat)
		return (NULL);
	while (i < (size_s1 + size_s2))
	{
		if (i < size_s1)
			concat[i] = s1[i];
		else if (i < (size_s1 + size_s2))
			concat[i] = s2[i - size_s1];
		i++;
	}
	concat[i] = '\0';
	return (concat);
}
