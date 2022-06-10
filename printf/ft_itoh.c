/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:21:27 by kbrechin          #+#    #+#             */
/*   Updated: 2022/06/10 19:10:10 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_itoh(size_t n, int *counter, char c)
{
	if (c == 'x')
	{
		if (n >= 16)
			ft_itoh((n / 16), counter, c);
		*counter += write(1, &"0123456789abcdef"[n % 16], 1);
	}
	else
	{
		if (n >= 16)
			ft_itoh((n / 16), counter, c);
		*counter += write(1, &"0123456789ABCDEF"[n % 16], 1);
	}
}

void	ft_ptr(void *p, int *counter)
{
	*counter += write(1, "0x", 2);
	ft_itoh((size_t)p, counter, 'x');
}
