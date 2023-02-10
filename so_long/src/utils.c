/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:18:32 by kbrechin          #+#    #+#             */
/*   Updated: 2023/02/10 18:51:57 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../so_long.h"

int	destroy_program(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free(game->map);
	free(game);
	exit(1);
}

int	destroy_error(t_game *game)
{
	ft_printf("Error\nInvalid Map Character\n");
	mlx_destroy_window(game->mlx, game->win);
	free(game->map);
	free(game);
	exit(1);
}

void	free_map(char **map, t_game *game)
{
	int	y;

	y = game->map_h + 1;
	while (--y)
		free(map[y]);
}

void	put_num(int num)
{
	if (num > 9)
	{
		put_num(num / 10);
		put_num(num % 10);
	}
	else
		write(1, (&num + '0'), 1);
}

void	player_pos(t_game *game, int direction)
{
	if (direction == 0)
	{
		game->player.pos.y -= 1;
		ft_printf("moves = %d\ncoings = %d/%d\n", game->movies++,
			game->current_coins, game->coins);
	}
	if (direction == 1)
	{
		game->player.pos.y += 1;
		ft_printf("moves = %d\ncoings = %d/%d\n", game->movies++,
			game->current_coins, game->coins);
	}
	if (direction == 2)
	{
		game->player.pos.x += 1;
		ft_printf("moves = %d\ncoings = %d/%d\n", game->movies++,
			game->current_coins, game->coins);
	}
	if (direction == 3)
	{
		game->player.pos.x -= 1;
		ft_printf("moves = %d\ncoings = %d/%d\n", game->movies++,
			game->current_coins, game->coins);
	}
}
