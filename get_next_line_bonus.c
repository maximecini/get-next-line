/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 02:03:30 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/12/09 17:39:35 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(char *buffer)
{
	int		size_line;
	char	*dest;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	size_line = i;
	dest = malloc((i + 2) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (buffer && buffer[i] && i < size_line + 1)
	{
		dest[i] = buffer[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*read_file(int fd, char *res)
{
	int		byte_read;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	byte_read = 1;
	while (!ft_strchr(buffer, '\n') && byte_read != 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			free(res);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		res = ft_strjoin(res, buffer);
	}
	free(buffer);
	return (res);
}

char	*ft_next_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*dest;
	int		lengt_buffer;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	lengt_buffer = ft_strlen(buffer) - i;
	dest = malloc((lengt_buffer + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		dest[j++] = buffer[i++];
	dest[j] = '\0';
	free(buffer);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*buffer[FOPEN_MAX];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > FOPEN_MAX)
		return (0);
	buffer[fd] = read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_get_line(buffer[fd]);
	buffer[fd] = ft_next_buffer(buffer[fd]);
	return (line);
}

// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;
// 	fd1 = open("tests/test.txt", O_RDONLY);
// 	fd2 = open("tests/test2.txt", O_RDONLY);
// 	fd3 = open("tests/test3.txt", O_RDONLY);
// 	i = 1;
// 	while (i < 7)
// 	{
// 		line = get_next_line(fd1);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		line = get_next_line(fd2);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		line = get_next_line(fd3);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// }
