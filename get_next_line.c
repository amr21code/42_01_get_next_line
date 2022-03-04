/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amr21code <a@n.de>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:05:01 by amr21code         #+#    #+#             */
/*   Updated: 2022/03/04 19:49:24 by amr21code        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	str_count;

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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((char *)dest + i) = *((char *)src + i);
		i++;
	}
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	size_t		i;
	size_t		exit;
	char		*main_buf;
	size_t		main_size;
	char		*tmp;

	main_size = BUFFER_SIZE;
	exit = 1;
	i = 0;
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE == 0)
		return (NULL);
	main_buf = (char *)ft_calloc(main_size, sizeof(*main_buf));
	if (!buf)
		buf = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(*buf));
	while (exit > 0)
	{
		while (buf[i])
			i++;
		exit = read(fd, &buf[i], BUFFER_SIZE);
		//printf("ex %ld\n", exit);
		//printf("read %c\n", buf[i]);
		while (i < BUFFER_SIZE && buf[i] != '\n' && exit > 0)
			i++;
		//printf("i %ld\n", i);
		if (buf[i] == '\n')
			exit = 0;
		if (i >= (main_size - ft_strlen(main_buf) - 1))
		{
			tmp = (char *)ft_calloc((main_size + BUFFER_SIZE), sizeof(*tmp));
			ft_memcpy(tmp, main_buf, main_size);
			free(main_buf);
			main_buf = (char *)ft_calloc((main_size + main_size), sizeof(*main_buf));
			ft_memcpy(main_buf, tmp, main_size);
			main_size += BUFFER_SIZE;
			free(tmp);
		}
		ft_memcpy(ft_strchr(main_buf, '\0'), buf, (i + 1));
		//printf("buf %s\n", main_buf);
		if (i == (BUFFER_SIZE - 1))
		{
			ft_bzero(buf, BUFFER_SIZE);
			i = 0;
		}
		else if (ft_strchr(buf, '\n'))
			ft_strncpy(buf, (ft_strchr(buf, '\n') + 1), BUFFER_SIZE);
		else
		{
			ft_bzero(buf, BUFFER_SIZE);
			i = 0;
		}
		//printf("ex %ld\n", exit);
		//printf("mb %s\n", main_buf);
	}
	if (!exit && !main_buf[0])
	{
		free(main_buf);
		//printf("\n------ PASSED -----\n");
		return (NULL);
	}
	return (main_buf);
}

			//printf("m%c j%d ", buf[j - 1], j);
			//printf("\n%c\n", main_buf[i - 1]);
	//printf("\n");
void	ft_putstr_fd(char *str, int fd)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		write(fd, &str[count], 1);
		count++;
	}
}
/*
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*ptr;
	fd = open("./test.txt", O_RDONLY);
		ptr = (char *)get_next_line(fd);
		//printf("%p\n", ptr);
		if (ptr)
		ft_putstr_fd(ptr, 1);
		ptr = (char *)get_next_line(fd);
		if (ptr)
		ft_putstr_fd(ptr, 1);
		ptr = (char *)get_next_line(fd);
		if (ptr)
		ft_putstr_fd(ptr, 1);
		ptr = (char *)get_next_line(fd);
		if (ptr)
			ft_putstr_fd(ptr, 1);
		ptr = (char *)get_next_line(fd);
		if (ptr)
			ft_putstr_fd(ptr, 1);
		//printf("\n%s\n", ptr);
	free(ptr);
	close(fd);
}*/
