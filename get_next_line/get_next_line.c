/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:09:52 by kbrechin          #+#    #+#             */
/*   Updated: 2022/08/31 14:27:25 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* If a new line (\n) or null teriminator (\0) is located
   within the string it will return its position as
   a size_t */  
size_t	detect_line(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

/* This function allows for the continuous reading of the 
   file discriptor (fd) using the read function at a rate
   determined by BUFFER_SIZE. [*2] returning the static string (store)
   after a new line is detected or [*1] until read reaches end of file*/
char	*read_line(int fd, char *store, char *buffer)
{
	int		read_return;

	read_return = read(fd, buffer, BUFFER_SIZE);
	while (read_return != -1)
	{
		if (read_return == 0)// [*1]
			return (store);
		buffer[read_return] = '\0';
		if (!store)
			store = malloc(BUFFER_SIZE + 1);
		store = ft_strjoin(store, buffer);
		if (store[detect_line(store)] == '\n')// [*2]
			return (store);
		read_return = read(fd, buffer, BUFFER_SIZE);
	}
	return (NULL);
}

/* Clean will activate after the read_line function hits a \n in the 
   fd and will take a substring starting after the \n*/
char	*Clean(char *line)
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

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	line = read_line(fd, store, buffer);
	free(buffer);
	if (!line)
		return (NULL);
	store = Clean(line);
	return (line);
}