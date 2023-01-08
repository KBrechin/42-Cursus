/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:18:32 by kbrechin          #+#    #+#             */
/*   Updated: 2023/01/08 16:36:05 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../so_long.h"

// takes a copy of the game map to alter
char	**copy_map(t_game *game)
{
	int		y;
	int		x;
	char	**map;

	map = malloc(sizeof(char *) * game->map_h);
	y = -1;
	while (++y < game->map_h)
	{
		map[y] = malloc(game->map_w);
		x = -1;
		while (++x < game->map_w)
			map[y][x] = game->map[y][x];
	}
	return (map);
}

//changes walkable points to s and checks coins and exits located
void	mark(int x, int y, char **map, t_game *game)
{
	if (map[y][x] == '0')
		map[y][x] = 's';
	else if (map[y][x] == 'C')
	{
		map[y][x] = 's';
		game->current_coins++;
	}
	else if (map[y][x] == 'E')
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

//checks if map in each direction is walkable and then marks that point 
int	scan_directions(int x, int y, char **map, t_game *game)
{
	int	moved;

	moved = 0;
	if (is_walkable(x - 1, y, map)) /*left*/
	{
		mark(x - 1, y, map, game);
		moved++;
	}
	if (is_walkable(x + 1, y, map)) /*right*/
	{
		mark(x + 1, y, map, game);
		moved++;
	}
	if (is_walkable(x, y - 1, map)) /*up*/
	{
		mark(x, y - 1, map, game);
		moved++;
	}
	if (is_walkable(x, y + 1, map)) /*down*/
	{
		mark(x, y + 1, map, game);
		moved++;
	}
	return (moved);
}

void	scanner(t_game *game, char **map)
{
	int	moves;
	int	x;
	int	y;

	moves = 1;
	game->current_coins = 0;
	game->current_exits = 0;
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
}
