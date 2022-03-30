/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:06:19 by kbrechin          #+#    #+#             */
/*   Updated: 2022/02/28 16:16:41 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	int	i;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	i = 0;
	if (dstsize < dstlen + 1)
		return (dstsize + srclen);
	while (src[i] && dstsize > (dstlen + 1 + i))
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = 0;
	return (dstlen + srclen);
}
