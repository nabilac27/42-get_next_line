#include "get_next_line.h"

char	*read_into_buffer(char buffer[], int fd)
{
	int		bytes_read;
	char	*whole_line;

	whole_line = NULL;
	whole_line = ft_strjoin_gnl(whole_line, buffer); // malloc
	if (whole_line == NULL)
		return (ft_buffer_to_zero(buffer),NULL);

	// ft_buffer_to_zero(buffer);

	while (ft_strchr(buffer, '\n') == 0) // if there's no new line
	{
        // ssize_t read(int fildes, void *buf, size_t nbyte);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
        buffer[bytes_read] = '\0';
		if (bytes_read == 0) // EOF
		{
            ft_buffer_to_zero(buffer);
			break;
		}
        if (bytes_read < 0) // EOF
		{
            return (NULL);
        }
		// printf("bytes_read = %d\n", bytes_read);
		whole_line = ft_strjoin_gnl(whole_line, buffer);
		if (whole_line == NULL)
			return (ft_buffer_to_zero(buffer), NULL);
		// printf("whole line = [%s]\n", whole_line);
	}
	return (whole_line);
}

void	shift_left_till_newline(char buffer[])
{
	char	*line;
	int		i;

	i = 0;

	line = ft_strchr(buffer, '\n');
	while (i < ft_strlen(line) - 1)
	{
		buffer[i] = line[i + 1];
		i++;
	}
	while (i < BUFFER_SIZE)
	{
		buffer[i] = '\0';
		i++;
	}
}

char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char *line;
	char *whole_line;
	int len_line;

    if(fd < 0 || BUFFER_SIZE <= 0 || read(fd,0,0) < 0)
    {
        ft_buffer_to_zero(buffer);
        return(NULL);
    }
        // printf("buffer = [%s]\n", buffer);
	if (ft_strchr(buffer, '\n') != 0)
	{
		shift_left_till_newline(buffer);
	}

        // printf("buffer = [%s]\n", buffer);
	whole_line = read_into_buffer(buffer, fd);
	if(whole_line == NULL)
	{
		return (ft_buffer_to_zero(buffer), NULL);
	}
	if (ft_strlen(whole_line) == 0)
	{
		free(whole_line);
		return (NULL);
	}
    // if (ft_strchr(whole_line, '\n'))
    // {
        //  printf("whole_line = [%s]\n", whole_line);
        len_line = ft_strlen(whole_line) - ft_strlen(ft_strchr(whole_line, '\n')) + 2;
        // printf("len_line = %d\n", len_line);
        // exit(0);
        line = malloc(len_line * sizeof(char)); // allocate free place for the line
		if (line == NULL)
		{
			return (ft_buffer_to_zero(buffer), free(whole_line), NULL);
		}
        ft_strlcpy(line, whole_line, len_line);
    // }

    // else
	// {
    //     printf("whole_line = [%s]\n", whole_line);
    //     line = malloc((ft_strlen(buffer) + 1) * sizeof(char));
    //     ft_strlcpy(line, whole_line, ft_strlen(whole_line) + 1);
    // }
		// copy till \n from wholeline into line

	return (free(whole_line), line);
}