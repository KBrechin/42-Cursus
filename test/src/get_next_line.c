/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:09:52 by kbrechin          #+#    #+#             */
/*   Updated: 2022/12/05 18:18:56 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	detect_line(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

char	*read_line(int fd, char *store, char *buffer)
{
	int		read_return;

	read_return = read(fd, buffer, 1);
	while (read_return != -1)
	{
		if (read_return == 0)
			return (store);
		buffer[read_return] = '\0';
		if (!store) 
			store = malloc(1 + 1);
		store = ft_strjoin(store, buffer);
		if (store[detect_line(store)] == '\n')
			return (store);
		read_return = read(fd, buffer, 1);
	}
	return (NULL);
}

char	*clean(char *line)
{
	size_t		i;
	char		*remainder;

	remainder = NULL;
	i = detect_line(line) + 1;
	if (!line[i - 1])
		return (remainder);
	if (line[i])
		remainder = ft_substr(line, i, ft_strlen(line) - i);
	line[i] = '\0';
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*line;
	char		*buffer;

	if (fd < 0)
		return (NULL);
	buffer = malloc(1 + 1);
	line = read_line(fd, store, buffer);
	free(buffer);
	if (!line)
		return (NULL);
	store = clean(line);
	return (line);
}
