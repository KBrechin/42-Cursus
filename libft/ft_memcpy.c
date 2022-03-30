/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:13:32 by kbrechin          #+#    #+#             */
/*   Updated: 2022/03/02 14:46:23 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *udst;
	unsigned char *usrc;
	int i;

	i = 0;
	udst = (unsigned char *)dest;
	usrc = (unsigned char *)src;
	while (n--)
	{
		udst[i] = usrc[i];
		i++;
	}
	return (dest);
}
