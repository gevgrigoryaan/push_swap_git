/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:19:18 by gegrigor          #+#    #+#             */
/*   Updated: 2026/03/05 20:35:20 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*beg_of_new_line(char *line)
{
	size_t	i;
	char	*rem;

	if (!line || !*line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i] || !line[i + 1])
		return (NULL);
	rem = ft_strdupg(&(line[i + 1]));
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
		return (free(storage), NULL);
	bytes = 1;
	while (!(storage && ft_strchrg(storage, '\n')) && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(storage);
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		tmp = storage;
		storage = ft_strjoing(tmp, buff);
		if (tmp)
			free(tmp);
	}
	free(buff);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = read_chunks(fd, storage);
	if (!storage)
		return (NULL);
	line = storage;
	if (!line || !(*line))
		return (free(storage), storage = NULL, NULL);
	storage = beg_of_new_line(line);
	return (line);
}
