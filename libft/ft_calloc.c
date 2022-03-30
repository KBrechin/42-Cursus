/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:15:19 by kbrechin          #+#    #+#             */
/*   Updated: 2022/03/02 14:26:22 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*i;

	if (!(i = malloc(count * size)))
	{
		return (0);
	}
	ft_bzero(i, (count * size));
	return (i);
}
