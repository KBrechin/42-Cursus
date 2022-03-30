/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:29:50 by kbrechin          #+#    #+#             */
/*   Updated: 2022/02/28 17:01:12 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t 	c;
	size_t	needlen;

	needlen = ft_strlen(needle);
	i = 0;
	c = 0;
	if (!needle[0])
		return ((char *)haystack);
	if (!needle)
		return (0);
	while (*haystack && i < len)
	{
		while (haystack[i + c] == needle[c] && i + c <  len
			   && haystack[i + c] && needle[c])
			c++;
		if (c == needlen)
				return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
