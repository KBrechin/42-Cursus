/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:56:56 by kbrechin          #+#    #+#             */
/*   Updated: 2022/08/08 17:21:43 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_handeler(char c, va_list *args, int *counter)
{
	if (c == 'c')
		*counter += ft_putchar(va_arg(*args, int));
	else if (c == 's')
		*counter += ft_putstr(va_arg(*args, char *));
	else if (c == 'X' || c == 'x')
		ft_itoh(va_arg(*args, unsigned int), counter, c);
	else if (c == 'i' || c == 'd')
		ft_putnbr(va_arg(*args, int), counter);
	else if (c == 'p')
		ft_ptr(va_arg(*args, void *), counter);
	else if (c == 'u')
		ft_uputnbr(va_arg(*args, unsigned int), counter);
	else if (c == '%')
		*counter += ft_putchar('%');
	else if (c != 0)
		*counter += ft_putchar(c);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		counter;
	va_list	args;

	i = 0;
	counter = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (!str[i])
				break ;
			flag_handeler(str[i], &args, &counter);
		}
		else
			counter += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (counter);
}
