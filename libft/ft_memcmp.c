/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:41:15 by kbrechin          #+#    #+#             */
/*   Updated: 2022/02/28 10:56:25 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*us1;
	const unsigned char	*us2;
	size_t	i;

	i = 0;
	us1 = (const unsigned char *)s1;
	us2 = (const unsigned char *)s2;
	while (n--)
	{
		if (us1[i] != us2[i])
		{
			return (us1[i] - us2[i]);
		}
		i++;
	}
	return (0);
}
