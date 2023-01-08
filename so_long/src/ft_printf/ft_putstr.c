/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:18:58 by kbrechin          #+#    #+#             */
/*   Updated: 2023/01/08 14:31:44 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// int	ft_strlen(char *c)
// {
// 	int	i;

// 	i = 0;
// 	while (c[i] != '\0')
// 	{
// 		i++;
// 	}	
// 	return (i);
// }

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *c)
{
	if (!c)
		c = "(null)";
	return (write(1, c, ft_strlen(c)));
}
