/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:18:32 by kbrechin          #+#    #+#             */
/*   Updated: 2023/02/10 19:11:53 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../so_long.h"

int	inputs(int key, t_game *game)
{
	int	x;
	int	y;

	x = game->player.pos.x;
	y = game->player.pos.y;
	if (key == ESC)
		destroy_program(game);
	if (key == UP_KEY && game->map[y - 1][x] != '1')
		player_pos(game, 0);
	if (key == DOWN_KEY && game->map[y + 1][x] != '1')
		player_pos(game, 1);
	if (key == RIGHT_KEY && game->map[y][x + 1] != '1')
		player_pos(game, 2);
	if (key == LEFT_KEY && game->map[y][x - 1] != '1')
		player_pos(game, 3);
	update_map(game);
	return (0);
}

void	open_imgs(t_game *game)
{
	int	h;
	int	w;

	game->player.p_img = mlx_xpm_file_to_image(&game->mlx,
			"./textures/fish.xpm", &h, &w);
	game->tile.ground = mlx_xpm_file_to_image(&game->mlx,
			"./textures/ground.xpm", &h, &w);
	game->tile.coin = mlx_xpm_file_to_image(&game->mlx,
			"./textures/plant_01.xpm", &h, &w);
	game->tile.wall = mlx_xpm_file_to_image(&game->mlx,
			"./textures/wall.xpm", &h, &w);
	game->tile.exit = mlx_xpm_file_to_image(&game->mlx,
			"./textures/exit.xpm", &h, &w);
}

int	game_start(t_game *game, char *path)
{
	game->coins = 0;
	game->movies = 0;
	map_importer(game, path);
	game->win_size.x = game->map_w * 64;
	game->win_size.y = game->map_h * 64;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,
			game->win_size.x,
			game->win_size.y, "so_long");
	return (0);
}

int	flood_fill(t_game *game)
{
	char				**map;
	int					moves;
	unsigned int		try;

	try = 0;
	game->current_coins = 0;
	game->current_exits = 0;
	game->p = 0;
	map = copy_map(game);
	moves = 1;
	while (moves > 0 && try++ != 100)
	{
		moves = scanner(game, map);
		if (try == 99)
			ft_printf("timeout!");
	}
	free(map);
	ft_printf("Coins found = %d/%d\nExits found = %d/%d\nPlayers found = %d/%d\n",
		game->current_coins, game->coins, game->current_exits, 1, game->p, 1);
	if (game->current_coins == game->coins && game->current_exits == 1
		&& game->p == 1)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (1);
	game = malloc(sizeof(t_game));
	game_start(game, argv[1]);
	open_imgs(game);
	set_map(game);
	if (!flood_fill(game) || !check_map(game))
	{
		ft_printf("Error\nSomething went wrong!\n");
		destroy_program(game);
		return (0);
	}
	mlx_hook(game->win, 2, 0, inputs, game);
	mlx_loop(game->mlx);
}
