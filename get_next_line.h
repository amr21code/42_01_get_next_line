/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amr21code <a@n.de>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:05:06 by amr21code         #+#    #+#             */
/*   Updated: 2022/03/08 18:20:37 by amr21code        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *s, int n);
void	*ft_calloc(int elem, int elsize);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
