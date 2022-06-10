/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:20:19 by kbrechin          #+#    #+#             */
/*   Updated: 2022/06/10 19:10:16 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_intlen(unsigned int n)
{
	unsigned int	len;

	len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

void	ft_putnbr(int n, int *counter)
{
	if (n == -2147483648)
	{
		*counter += write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		*counter += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, counter);
		ft_putnbr(n % 10, counter);
	}
	else
		*counter += ft_putchar(n + 48);
}

void	ft_uputnbr(unsigned int n, int *counter)
{
	if (n >= 10)
		ft_uputnbr(n / 10, counter);
	ft_putchar(n % 10 + '0');
	(*counter)++;
}
