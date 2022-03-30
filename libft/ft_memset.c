/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:26:20 by kbrechin          #+#    #+#             */
/*   Updated: 2022/02/25 11:43:51 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int i;
	unsigned char *ub;

	ub = (unsigned char *)b;
	i = 0;
	while (len--)
	{
		ub[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
