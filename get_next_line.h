
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

#include <fcntl.h>
#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd);

char	*ft_strjoin_gnl(char  *s1, char  *s2);
char	*ft_strchr(const char *ptr_string, int ptr_find);
int	    ft_strlen(const char *str);
int	    ft_strlcpy(char *dst, const char *src, int dstsize);
 void	ft_buffer_to_zero(char buffer[]);
#endif