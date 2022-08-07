/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:40:08 by kbrechin          #+#    #+#             */
/*   Updated: 2022/08/07 19:34:11 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


/*returns the length of a string*/
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

/*this function detects if there is a new line present in a string returning a positive if there is or zero if not*/
int	detect_line(char *store_str)
{
	int	i;

	i = 0;
	if (!store_str)
		return (0);
	while (store_str[i])
	{
		if (store_str[i] == '\n')
			return(++i);
		i++;
	}
	return(0);
}

/*Joins two strings together*/
char	*ft_strjoin(char *str_store, char *str_buf)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	str = (char *)malloc(ft_strlen(str_store) + ft_strlen(str_buf));
	if (!str)
		return (NULL);
	while (str_store[j] != '\0')
		str[i++] = str_store[j++];
	j = 0;
	while (str_buf[j] != '\0')
		str[i++] = str_buf[j++];
	str[i++] = '\0';
	if (str_store)
		free(str_store);
	return (str);
}
/*clears the sting up to the new line*/
char *str_cleaning(char *store_str)
{
	char	*clean_str;
	int		i;
	int		store_len;

	store_len = detect_line(store_str);
	clean_str = (char *)malloc(ft_strlen(store_str) - detect_line(store_str));
	if (!clean_str)
		return (NULL);
	i = 0;
	while (store_str[store_len] != '\0')
		clean_str[i++] = store_str[store_len++];
	clean_str[i++] = '\0';
	if (store_str)
		free(store_str);
	return (clean_str);
}

/*this function returns the string up until the new line ('\n') in the file desctriptor (fd) */
char *return_line(char *store_str)
{
	char		*new_line;
	int 		i;
	int			j;

	i = 0;
	j = 0;
	new_line = (char *)malloc(detect_line(store_str));
	new_line[detect_line(store_str)] = '\0';
	if (!new_line)
		return (NULL);
	while (store_str[i] != '\0' && store_str[i] != '\n')
		new_line[j++] = store_str[i++];	
	new_line[j] = '\0';
	return (new_line);
}

/*typedef struct mal_str{
	static char	*store_handoff;
	int			BUFFER_SIZE;

	BUFFER_SIZE = 100;
	store_handoff = (char *)malloc(BUFFER_SIZE);
} mal_str*/

char *get_line(int fd)
{
	char		*buf;
	char		*store_carry;
	static char	*store_handoff;
	char		*return_str;
	int			n;
	int			BUFFER_SIZE;
	 
	BUFFER_SIZE = 100;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(BUFFER_SIZE);
	store_carry = (char *)malloc(BUFFER_SIZE);
	if (store_handoff != NULL)
		store_carry = store_handoff;
	while (detect_line(store_carry) == 0)
	{
		n = read(fd, buf, BUFFER_SIZE); 
		buf[n] = '\0';
		if (n == 0)
			break;
		store_carry = ft_strjoin(store_carry, buf);
	}
	if (*buf)
		free(buf);
	return_str = return_line(store_carry);
	store_handoff = str_cleaning(store_carry);
	if (*return_str)
		return (return_str);
	return (NULL);
}

int main()
{
	char	*line;
	int		i;
	int		fd1;

	fd1 = open("test.txt", O_RDONLY);
	i = 0;
	printf("\n\nstarting\n\n");
	while (1)
	{
		line = get_line(fd1);
		if (line)
			printf("line [%02d]: %s\n", i, line);
		if (line == NULL)
			break;
		free(line);
		i++;
	}
	close(fd1);
	return (0);
}
