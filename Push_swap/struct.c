/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:31:49 by kbrechin          #+#    #+#             */
/*   Updated: 2023/02/19 16:46:17 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*revstr(char *str)
{
	int		i;
	int		len;
	char	*tmp;

	len = ft_strlen(str);
	while (len != 0)
	{

	}
	return (tmp);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	write(1, "\n", 1);
}

int main()
{
	char	*olleh = revstr("hello");
	ft_putstr("hi");
	ft_putstr(olleh);
}