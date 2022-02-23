/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amr21code <a@n.de>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:05:01 by amr21code         #+#    #+#             */
/*   Updated: 2022/02/23 09:51:31 by amr21code        ###   ########.fr       */
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
	void	*buf;
	size_t	i;
	size_t	j;
	size_t	exit;
	size_t	buffsize;
	void	*main_buf;
	size_t	main_size;

	main_size = 25;
	buffsize = 1;
	exit = 1;
	i = 0;
	j = 0;
	if (!fd)
		return (NULL);
	buf = malloc(sizeof(*buf) * (buffsize));
	main_buf = malloc(sizeof(*main_buf) * main_size);
	while (!(exit < buffsize) && *(char *)(main_buf + i - 1) != '\n')
	{
		exit = read(fd, (buf + j), 1);
		j++;
		if (j == buffsize)
		{
			ft_memcpy(main_buf, buf, buffsize);
			j = 0;
		}
		i++;
	}
	if (i == 1 && !exit)
		return (NULL);
	return (main_buf);
}

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

#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*ptr;

	fd = open("./test.txt", O_RDONLY);
		ptr = (char *)get_next_line(fd);
		ft_putstr_fd(ptr, 1);
		ptr = (char *)get_next_line(fd);
		ft_putstr_fd(ptr, 1);
		ptr = (char *)get_next_line(fd);
		ft_putstr_fd(ptr, 1);
		ptr = (char *)get_next_line(fd);
		if (ptr)
			ft_putstr_fd(ptr, 1);
		printf("\n%s\n", ptr);
	free(ptr);
	close(fd);
}
