#include "get_next_line.h"

char	*ft_strjoin_gnl(char  *s1, char  *s2)
{
	char	*new_str;
	int		s1_len;
	int		s2_len;

	if (s1 == NULL)
		s1_len = 0;
	else
		s1_len = ft_strlen(s1);
	if (s2 == NULL)
		s2_len = 0;
	else
		s2_len = ft_strlen(s2);
	new_str = (char *)malloc(s1_len + s2_len + 1);
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s1, s1_len + 1);
	ft_strlcpy(new_str + s1_len, s2, s2_len + 1);
	return (free(s1), new_str);
}

char	*ft_strchr(const char *ptr_string, int ptr_find)
{
	int		i;
	char	char_ptr_find;

	i = 0;
	char_ptr_find = (char)ptr_find;
	while (ptr_string && ptr_string[i] != '\0')
	{
		if (ptr_string[i] == char_ptr_find)
		{
			return ((char *)&ptr_string[i]);
		}
		i++;
	}
	if (char_ptr_find == '\0')
		return ((char *)&ptr_string[i]);
	return (0);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (dst && src && src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (dst && dstsize > 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

void	ft_buffer_to_zero(char buffer[])
{
	int i = 0;
	while (i < BUFFER_SIZE)
	{
		buffer[i] = '\0';
		i++;
	}
}