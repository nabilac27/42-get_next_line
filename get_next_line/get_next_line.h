/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:50:32 by nchairun          #+#    #+#             */
/*   Updated: 2024/12/25 23:30:25 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// get_next_line
char	*get_next_line(int fd);
char	*read_into_buffer(char *buffer, int fd);
void	next_line(char buffer[]);
void	clear_buffer(char buffer[]);

// get_next_line_utils
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *ptr_string, int ptr_find);
int		ft_strlen(const char *str);
int		ft_strlcpy(char *dst, const char *src, int dstsize);
char	*ft_strjoin_free(char *s1, char *s2);

#endif