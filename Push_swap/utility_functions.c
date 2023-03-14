/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:48:10 by kbrechin          #+#    #+#             */
/*   Updated: 2023/03/14 18:17:30 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *string)
{
	int	sign;
	int	result;
	int	i;

	i = 0;
	result = 0;
	sign = 1;
	/*iterate through string until a number or sign is found*/
	while (!ft_isdigit(string[i]))
		i++;
	if (string[i] == '-' && ft_isdigit(string[i + 1]))
	{
		i++;
		sign = -1;
	}
	while (string[i] >= '0' && string[i] <= '9')
	{
		result = result * 10 + string[i] - '0';
		i++;
	}
	return (sign * result);
}

int	main(void)
{
	printf("%d\n", ft_atoi("egijgipjwp1000"));
}
