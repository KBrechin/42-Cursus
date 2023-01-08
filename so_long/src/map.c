/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:35:52 by kbrechin          #+#    #+#             */
/*   Updated: 2023/01/08 18:55:43 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../so_long.h"

void	update_map(t_game *game)
{
	int	x;
	int	y;

	x = game->player.position.x;
	y = game->player.position.y;
	if (game->map[y][x] == 'C')
		game->coins--;
	else if (game->map[y][x] == 'E' && game->coins == 0)
		exit(1);
	if (game->map[game->last_y][game->last_x] == 'E')
		mlx_put_image_to_window(game->mlx, game->window,
			game->tile.exit, game->last_x * 64, game->last_y * 64);
	else
		mlx_put_image_to_window(game->mlx, game->window,
			game->tile.ground, game->last_x * 64, game->last_y * 64);
	mlx_put_image_to_window(game->mlx, game->window, game->player.p_img,
		game->player.position.x * 64, game->player.position.y * 64);
	game->last_x = game->player.position.x;
	game->last_y = game->player.position.y;
}

void	map_importer(t_game *game, char *path)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(path, O_RDONLY);
	game->map = malloc(sizeof(char *) * 100);
	while (1)
	{
		game->map[i] = get_next_line(fd);
		if (game->map[i] == NULL)
			break ;
		i++;
	}
	game->map_h = i;
	game->map_w = ft_strlen(game->map[0]) - 1;
}

void	draw_map(t_game *game, int x, int y)
{
	if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->window,
			game->tile.ground, x * 64, y * 64);
	else if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->window,
			game->tile.wall, x * 64, y * 64);
	else if (game->map[y][x] == 'P')
	{
		game->player.position.x = x;
		game->player.position.y = y;
		game->last_x = game->player.position.x;
		game->last_y = game->player.position.y;
		mlx_put_image_to_window(game->mlx, game->window, game->player.p_img,
			game->player.position.x * 64, game->player.position.y * 64);
	}
	else if (game->map[y][x] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->tile.coin, x * 64, y * 64);
		game->coins++;
	}
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->window,
			game->tile.exit, x * 64, y * 64);
}

int	check_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < game->map_w)
	{
		if (game->map[0][x] != '1' || game->map[game->map_h - 1][x] != '1')
		{
			ft_printf("1 needed at x = %d, y = %d\n", x, y);
			return (0);
		}
		x++;
	}
	while (y < game->map_h)
	{
		if (game->map[y][0] != '1' || game->map[y][game->map_w - 1] != '1')
		{
			ft_printf("1 needed at x = %d, y = %d\n", x, y);
			return (0);
		}
		y++;
	}
	return (1);
}

void	set_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_h)
	{
		x = 0;
		while (x < game->map_w)
		{
			draw_map(game, x, y);
			x++;
		}
		y++;
	}
}
