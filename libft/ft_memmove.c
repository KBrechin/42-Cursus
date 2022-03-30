/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:14:43 by kbrechin          #+#    #+#             */
/*   Updated: 2022/02/28 10:59:37 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*udst;
	unsigned char	*usrc;
	size_t	i;

	udst = (unsigned char *)dst;
	usrc = (unsigned char *)src;
	if (dst > src)
	{
		i = len - 1;
		while (len--)
		{
			udst[i] = usrc[i];
			i--;
		}
	}
	else
	{ 
		i = 0;
		while (len--)
		{
			udst[i] = usrc[i];
			i++;
		}
	}
	return (dst);
}
