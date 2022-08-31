/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:10:05 by kbrechin          #+#    #+#             */
/*   Updated: 2022/08/31 14:27:26 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_substr(const char *str, size_t start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	while (str[i] != '\0' && i < len)
	{
		sub[i] = str[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *start, char *end)
{
	int					i;
	unsigned int		j;
	char	*join;

	if (!start || !end)
		return (NULL);
	join = malloc(ft_strlen(start) + ft_strlen(end)+ 1);
	i = -1;
	while (start[++i])
		join[i] = start[i];
	j = 0;
	while (end[j])
		join[i++] = end[j++];
	join[i] = '\0';
	free (start);
	return (join);
}