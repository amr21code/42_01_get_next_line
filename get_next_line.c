/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amr21code <a@n.de>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:05:01 by amr21code         #+#    #+#             */
/*   Updated: 2022/03/05 18:38:36 by amr21code        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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

char	*ft_gnl_expand_buf(size_t *main_size, char *main_buf)
{
	char	*tmp;

	tmp = (char *)ft_calloc((*main_size + BUFFER_SIZE), sizeof(*tmp));
	ft_memcpy(tmp, main_buf, *main_size);
	free(main_buf);
	main_buf = (char *)ft_calloc((*main_size * 2), sizeof(*tmp));
	ft_memcpy(main_buf, tmp, *main_size);
	*main_size += BUFFER_SIZE;
	free(tmp);
	return (main_buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	size_t		i;
	size_t		exit;
	char		*main_buf;
	size_t		main_size;

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
		if (!ft_strchr(buf, '\n'))
		{
			while (buf[i])
				i++;
			exit = read(fd, &buf[i], BUFFER_SIZE);
			while (i < BUFFER_SIZE && buf[i] != '\n' && exit > 0)
				i++;
			if (i >= (main_size - ft_strlen(main_buf) - 1))
				main_buf = ft_gnl_expand_buf(&main_size, main_buf);
		}
		else
		{
			while (buf[i] != '\n')
				i++;
		}
		if (buf[i] == '\n')
			exit = 0;
		ft_memcpy(ft_strchr(main_buf, '\0'), buf, (i + 1));
		printf("mb*%s*nl", main_buf);
		if (ft_strchr(buf, '\n'))
			ft_strncpy(buf, (ft_strchr(buf, '\n') + 1), BUFFER_SIZE);
		else
		{
			ft_bzero(buf, BUFFER_SIZE);
			i = 0;
		}
		printf("\n------ PASSED -----\n");
	}
	if (!exit && !main_buf[0])
	{
		free(main_buf);
		return (NULL);
	}
	return (main_buf);
}





		//printf("ex %ld\n", exit);
		//printf("read %c\n", buf[i]);
		//printf("ex %ld\n", exit);
		//printf("buf %s\n", main_buf);
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
}
