/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 02:56:13 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/11/11 20:34:22 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../headers/get_next_line.h"

char	*fill_line(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (ft_substr(buffer, 0, i + 1));
		i++;
	}
	return (ft_strdup(buffer));
}

char	*read_and_store(int fd, char **s)
{
	char	*buffer;
	char	*temp;
	int		bytesread;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (1)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread < 0)
			return (free(buffer), NULL);
		buffer[bytesread] = '\0';
		temp = *s;
		if (*s)
			*s = ft_strjoin(*s, buffer);
		else
			*s = ft_strdup(buffer);
		free(temp);
		if (!*s || ft_strchr(*s, '\n') || bytesread < BUFFER_SIZE)
			break ;
	}
	return (free(buffer), *s);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!read_and_store(fd, &s) || !s || *s == '\0')
	{
		free(s);
		s = NULL;
		return (NULL);
	}
	line = fill_line(s);
	temp = s;
	s = ft_substr(s, ft_strlen(line), ft_strlen(s) - ft_strlen(line));
	free(temp);
	if (!s)
		return (free(line), NULL);
	return (line);
}
