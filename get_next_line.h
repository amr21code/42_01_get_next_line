/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:05:06 by anruland         #+#    #+#             */
/*   Updated: 2022/03/22 10:17:19 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

int		ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *s, int n);
void	*ft_calloc(int elem, int elsize);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_join(char *main_buf, char *buf);
char	*ft_read_file(int fd, char *main_buf);
char	*ft_prepare_line(const char *main_buf);
char	*ft_prepare_next(char *main_buf, unsigned int i, unsigned int j);
char	*get_next_line(int fd);
#endif
