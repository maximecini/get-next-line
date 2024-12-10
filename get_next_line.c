/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:03:16 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/12/10 11:13:50 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *buffer)
{
	int		size_line;
	char	*dest;
	int		i;

	i = 0;
	 if (!buffer)  // Vérification NULL ajoutée ici
        return (NULL);
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	size_line = i;
	dest = malloc((i + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (buffer && buffer[i] && i < size_line)
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
			return (free(buffer), free(res), NULL);
		if (byte_read == 0)
			break;
		buffer[byte_read] = '\0';
		res = ft_strjoin(res, buffer);
		if(!res)
			return  free(buffer),NULL;
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
	 if (!buffer)  
        return (NULL);
	if(!ft_strchr(buffer, '\n'))
		return free(buffer), NULL;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return free(buffer),(NULL);
	
	lengt_buffer = ft_strlen(buffer) - i;
	dest = malloc((lengt_buffer + 1) * sizeof(char));
	if (!dest)
		return free(buffer),(NULL);
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
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_next_buffer(buffer);
	return (line);
}
int	main(void)
{
	char	*line;
	int		fd1;

	fd1 = open("one_line_no_nl.txt", O_RDONLY);
	// line = get_next_line(49);
	// printf("line: <%s>\n",line);
	// free(line);
	line = get_next_line(fd1);
	printf("line: <%s>\n",line);
	free(line);
	line = get_next_line(fd1);
	printf("line: <%s>\n",line);
	free(line);

	close(fd1);
	return (0);
}
