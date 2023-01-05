/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:18:32 by kbrechin          #+#    #+#             */
/*   Updated: 2023/01/05 15:27:16 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../so_long.h"

char **copy_map(t_game *game)
{
	int y;
	int x;
	char **map;

	map = malloc(sizeof(char *) * game->map_h);
	y = -1;
	while (++y < game->map_h)
	{
		map[y] = malloc(game->map_w);
		x = -1;
		while (++x < game->map_w)
			map[y][x] = game->map[y][x];
	}
	return(map);
}

void	mark(int x, int y, char **map, t_game *game)
{
	if (map[y][x] == '0')
		map[y][x] = 's';
	else if(map[y][x] == 'C')
	{
		map[y][x] = 's';
		game->current_coins++;
	}
	else if(map[y][x] == 'E')
	{
		map[y][x] = 's';
		game->current_exits++;
	}
}

int	is_walkable(int x, int y, char **map)
{
	if (map[y][x] == '0' || map[y][x] == 'C' || map[y][x] == 'E')
		return (1);
	return (0);
}

int	scan_directions(int x, int y, char **map, t_game *game)
{
	int moved;

	moved = 0;
	if (is_walkable(x - 1, y, map)) // left
	{
		mark(x - 1, y, map, game);
		moved++;
	}
	if (is_walkable(x + 1, y, map)) // right
	{
		mark(x + 1, y, map, game);
		moved++;
	}
	if (is_walkable(x, y - 1, map)) // up
	{
		mark(x, y - 1, map, game);
		moved++;
	}
	if (is_walkable(x, y + 1, map)) // down
	{
		mark(x, y + 1, map, game);
		moved++;
	}
	return(moved);
}

int	flood_fill(t_game *game)
{
	int moves;
	int x;
	int y;
	char **map = copy_map(game);

	game->current_coins = 0;
	game->current_exits = 0;
	moves = 1;
	while (moves > 0)
	{
		y = -1;
		while (++y < game->map_h)
		{
			x = -1;
			while (++x < game->map_w)
			{
				if (map[y][x] == 'P' || map[y][x] == 's')
					moves = scan_directions(x, y, map, game);
			}
		}
	}
	mlx_string_put(game->mlx, game->window, 50, 50, 0x00FFFFFF, "hello world");
	free(map);
	printf("coins found = %d/%d\nexits found = %d/%d\n",game->current_coins, game->coins, game->current_exits, 1);
	if (game->current_coins == game->coins && game->current_exits > 0)
		return (0);
	return (1);
}