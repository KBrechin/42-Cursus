/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:18:32 by kbrechin          #+#    #+#             */
/*   Updated: 2023/02/10 18:57:42 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../so_long.h"

// takes a copy of the game map to alter
char	**copy_map(t_game *game)
{
	int		y;
	int		x;
	char	**map;

	map = malloc(sizeof(char *) * (game->map_h * game->map_w));
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
		map[y][x] = 'S';
	else if (map[y][x] == 'C')
	{
		map[y][x] = 'S';
		game->current_coins++;
	}
	else if (map[y][x] == 'E')
	{
		map[y][x] = 'S';
		game->current_exits++;
	}
	else if (map[y][x] == 'P')
	{
		map[y][x] = 'X';
		game->p++;
	}
}

int	is_walkable(int x, int y, char **map)
{
	if (map[y][x] == '0' || map[y][x] == 'C' || map[y][x] == 'E')
		return (1);
	return (0);
}

//checks if map in each direction is walkable and then marks that point 
void	scan_directions(int x, int y, char **map, t_game *game)
{
	if (is_walkable(x, y + 1, map))
		mark(x, y + 1, map, game);
	if (is_walkable(x, y - 1, map))
		mark(x, y - 1, map, game);
	if (is_walkable(x - 1, y, map))
		mark(x - 1, y, map, game);
	if (is_walkable(x + 1, y, map))
		mark(x + 1, y, map, game);
	if (map[y][x] == 'S' || map[y][x] == 's' || map[y][x] == 'E')
		map[y][x] = 'X';
	if (map[y][x] == 'P')
	{
		map[y][x] = 'p';
		game->p++;
	}
}

int	scanner(t_game *game, char **map)
{
	int	moves;
	int	x;
	int	y;

	moves = 0;
	y = 0;
	while (++y < game->map_h - 1)
	{
		x = 0;
		while (++x < game->map_w - 1)
		{
			if (map[y][x] == 'P' || map[y][x] == 'S')
			{
				scan_directions(x, y, map, game);
				moves++;
			}
		}
	}
	return (moves);
}
