/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gegrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:19:18 by gegrigor          #+#    #+#             */
/*   Updated: 2026/03/05 14:52:29 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*beg_of_new_line(char *line)
{
	size_t	i;
	char	*rem;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i] || !line[i + 1])
		return (NULL);
	rem = ft_strdup(&(line[i + 1]));
	if (!rem)
		return (NULL);
	line[i + 1] = '\0';
	if (!(*rem))
	{
		free(rem);
		rem = NULL;
	}
	return (rem);
}

static char	*read_chunks(int fd, char *storage)
{
	ssize_t	bytes;
	char	*buff;
	char	*tmp;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(storage, '\n') && bytes > 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		tmp = storage;
		storage = ft_strjoin(tmp, buff);
		if (!storage)
			return (free(tmp), free(buff), tmp = NULL, NULL);
	}
	free(buff);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage[FD_SETSIZE];
	char		*line;

	if (fd < 0 || fd >= FD_SETSIZE || BUFFER_SIZE <= 0)
	{
		free(storage[fd]);
		storage[fd] = NULL;
		return (NULL);
	}
	line = read_chunks(fd, storage[fd]);
	if (!line || !(*line))
		return (free(line), free(storage[fd]), storage[fd] = NULL, NULL);
	storage[fd] = beg_of_new_line(line);
	return (line);
}
