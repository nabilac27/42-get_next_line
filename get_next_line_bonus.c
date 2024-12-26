/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:55:23 by nchairun          #+#    #+#             */
/*   Updated: 2024/12/26 00:37:27 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	char		*store_line;
	int			len_line;

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (clear_buffer(buffer[fd]), NULL);
	if (ft_strchr(buffer[fd], '\n') != 0)
		next_line(buffer[fd]);
	store_line = read_into_buffer(buffer[fd], fd);
	if (store_line == NULL)
		return (clear_buffer(buffer[fd]), NULL);
	if (ft_strlen(store_line) == 0)
		return (free(store_line), NULL);
	len_line = ft_strlen(store_line) - ft_strlen(ft_strchr(store_line, '\n'));
	if (ft_strchr(store_line, '\n') != NULL)
		len_line = len_line + 1;
	line = malloc((len_line + 1) * sizeof(char));
	if (line == NULL)
		return (clear_buffer(buffer[fd]), free(store_line), NULL);
	ft_strlcpy(line, store_line, len_line + 1);
	free(store_line);
	return (line);
}

char	*read_into_buffer(char buffer[], int fd)
{
	int		bytes_read;
	char	*store_line;

	store_line = NULL;
	store_line = ft_strjoin_free(store_line, buffer);
	if (store_line == NULL)
		return (clear_buffer(buffer), NULL);
	while (ft_strchr(buffer, '\n') == 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		buffer[bytes_read] = '\0';
		if (bytes_read == 0)
		{
			clear_buffer(buffer);
			break ;
		}
		store_line = ft_strjoin_free(store_line, buffer);
		if (store_line == NULL)
			return (clear_buffer(buffer), NULL);
	}
	return (store_line);
}

void	next_line(char buffer[])
{
	char	*ptr_next_line;
	int		i;

	ptr_next_line = ft_strchr(buffer, '\n');
	if (ptr_next_line != NULL)
	{
		i = 0;
		ptr_next_line++;
		while (ptr_next_line[i] != '\0')
		{
			buffer[i] = ptr_next_line[i];
			i++;
		}
		buffer[i] = '\0';
	}
	else
		clear_buffer(buffer);
}

void	clear_buffer(char buffer[])
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
		buffer[i++] = '\0';
}

/*
	TEST FUNCTION
*/
int	main(void)
{
	char	*line;
	int		fd1 = open("./abc.txt", O_RDONLY);
	int		fd2 = open("./def.txt", O_RDONLY);
	printf("fd1 = %d\n, fd2 = %d\n", fd1, fd2);
	int i = 1;
	while ((line = get_next_line(fd1)))
	{
		printf("file1 line(%d) =[%s]\n", i++, line);
		free(line);
	}
	i = 1;
	while ((line = get_next_line(fd2)))
	{
		printf("file2 line(%d) =[%s]\n", i++, line);
		free(line);
	}
	close(fd1);
	close(fd2);
	return (0);
}
