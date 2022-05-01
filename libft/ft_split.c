/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:47:11 by kbrechin          #+#    #+#             */
/*   Updated: 2022/05/01 14:19:48 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	dcut(const char *str, const char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

static int	dlen( const char *s, const char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	wordlen;
	size_t	i;
	int		line;

	wordlen = 0;
	line = -1;
	i = 0;
	split = (char **)malloc(sizeof(*s) * (dcut(s, c) + 1));
	if (!s || split == 0)
		return (NULL);
	while (++line < dcut(s, c))
	{
		split[line] = malloc(dlen(&s[i], c) + 1);
		if (split[line] == 0)
			return (NULL);
		while (s[i] == c)
			i++;
		while (s[i] != c && *s)
			split[line][wordlen++] = s[i++];
		split[line][wordlen] = '\0';
	}
	split[line] = NULL;
	return (split);
}
