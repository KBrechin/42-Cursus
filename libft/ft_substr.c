/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:58:09 by kbrechin          #+#    #+#             */
/*   Updated: 2022/03/03 14:53:06 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	rlen;
	
	if (s == 0)
		return (0);
	rlen = ft_strlen(s + start);	
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (rlen < len)
		len = rlen;
	if (!(subs = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	ft_strlcpy(subs, s + start, len + 1);
	return (subs);
}
