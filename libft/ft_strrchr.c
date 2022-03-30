/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:13:48 by kbrechin          #+#    #+#             */
/*   Updated: 2022/02/24 15:34:10 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = (int)ft_strlen(s);
	if (!c)
		return ((char *)s + i);
	while (s[--i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
	}
	return(0);
}
