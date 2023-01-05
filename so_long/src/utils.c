/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:18:32 by kbrechin          #+#    #+#             */
/*   Updated: 2023/01/05 13:37:19 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../so_long.h"

int destroy_program(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	free(game->map);
	free(game);
	exit(0);
}

void	free_map(char **map, t_game *game)
{
	int y;

	y = game->map_h + 1;
	while (--y)
		free(map[y]);
}

void put_char(char c)
{
	write(1, &c, 1);
}

void	put_num(int num)
{
	if (num > 9)
	{
		put_num(num / 10);
		put_num(num % 10);
	}
	else
		put_char(num + '0');
}