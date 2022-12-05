/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:18:32 by kbrechin          #+#    #+#             */
/*   Updated: 2022/12/05 17:18:57 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"

int destroy_program(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	exit(0);
}

void move_down(t_game *game){
	static int	i;

	i = 64;
	mlx_clear_window(game->mlx, game->window);
	mlx_put_image_to_window(game->mlx, game->window, 
	game->tile.ground, game->player.position.x, game->player.position.y);
	game->player.position.y += 64;
	mlx_put_image_to_window(game->mlx, game->window, 
	game->player.player_img, game->player.position.x, game->player.position.y);
}

void update_map(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->window, 
	game->player.player_img, game->player.position.x, game->player.position.y);
}

int inputs(int key, t_game *game)
{
	if (key == ESC)
		destroy_program(game);
	if (key == KEY_NORTH)
		game->player.position.y -= 64;
	if (key == KEY_SOUTH)
		game->player.position.y += 64;
	if (key == KEY_EAST)
		game->player.position.x += 64;;
	if (key == KEY_WEST)
		game->player.position.x -= 64;
	update_map(game);
	return (0);
}

void open_player_img(t_game *game){
	game->player.player_img = mlx_xpm_file_to_image(game->mlx,
	 "../img/fish.xmp", &game->img_size.x, &game->img_size.y);
}

int	frame(t_game *game)
{
	
	return (1);
}

int	main(void)
{
	t_game *game;

	game = malloc(sizeof(t_game));
	game->win_size.x = 1980;
	game->win_size.y = 1080;

	game->player.position.x = 0;
	game->player.position.y = 0;

	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->win_size.x, game->win_size.y, "so_long");
	
	int h, w;
	game->player.player_img = mlx_xpm_file_to_image(&game->mlx, "./img/fish.xpm", &h, &w);
	game->tile.ground = mlx_xpm_file_to_image(&game->mlx, "./img/ground.xpm", &h, &w);

	int x;
	int y;

	x = 0;
	while (x < 50)
	{
		y = 0;
		while (y < 50)
		{
			mlx_put_image_to_window(game->mlx, game->window, 
			game->tile.ground, x * 64, y * 64);
			y++;
		}
		x++;
	}

	mlx_put_image_to_window(game->mlx, game->window, 
	game->player.player_img, game->player.position.x, game->player.position.y);
	mlx_hook(game->window, 2, 0, inputs, game);
	mlx_loop(game->mlx);
}
